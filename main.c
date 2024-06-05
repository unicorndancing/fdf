/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:14 by mlapique          #+#    #+#             */
/*   Updated: 2024/06/05 17:37:02 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fade_to_black(t_everything *eve)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_put_pixel(eve->image, i, j, 0x000000FF);
			j++;
		}
		j = 0;
		i++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_everything	*eve;

	eve = param;
	fade_to_black(eve);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		eve->zoom += 1;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		eve->zoom -= 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		eve->offsetx += (abs(eve->offsetx) / 10) + 50;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		eve->offsetx -= (abs(eve->offsetx) / 10) + 50;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		eve->offsety += (abs(eve->offsety) / 10) + 50;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		eve->offsety -= (abs(eve->offsety) / 10) + 50;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		eve->offsetz += 1;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		eve->offsetz -= 1;
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_PRESS)
		eve->angley += 0.2;
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
	{
		eve->angley -= 0.2;
		if (eve->angley < 0.0000)
			eve->angley = 10;
	}
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		eve->anglex += 0.2;
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
	{
		eve->anglex -= 0.2;
		if (eve->anglex < 0.0000)
			eve->anglex = 10;
	}
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		eve->anglez += 0.2;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		eve->anglez -= 0.2;
		if (eve->anglez < 0.0000)
			eve->anglez = 10;
	}
	if (keydata.key == 256)
		mlx_close_window(eve->mlx);
	createtab(eve);
}

int	ft_strlen_for_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (-666);
	while (tab[i])
	{
		if (verif_value(tab[i]) == -10)
			return (i);
		i++;
	}
	return (i);
}

int	size_map(int fd, int *i, int *pj)
{
	char	*line;
	char	**nbpoint;

	line = get_next_line(fd);
	if (!line)
		return (-666);
	while (line)
	{
		*i += 1;
		nbpoint = ft_split(line, ' ');
		if (!nbpoint)
			return (-666);
		if (*pj == -500)
			*pj = ft_strlen_for_tab(nbpoint);
		else if (*pj != ft_strlen_for_tab(nbpoint))
			return (-666);
		free(line);
		free(nbpoint);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	return (*i);
}

int	malloc_tab(t_point **tabpoint, int j, int i)
{
	int	index;

	index = 0;
	while (index < i)
	{
		tabpoint[index] = malloc(sizeof(*tabpoint[index]) * j + 1);
		if (tabpoint[index] == NULL)
			return (-666);
		index++;
	}
	return (1);
}

int	ini_eve(t_everything *eve, char *argv[], mlx_image_t *image, mlx_t	*mlx)
{
	int	h;
	int	w;

	if (argv[1] == NULL)
		return (-666);
	h = 0;
	w = -500;
	eve->fd = open(argv[1], O_RDONLY);
	eve->tabpoint = malloc(sizeof(t_point *) * size_map(eve->fd, &h, &w) + 1);
	if (eve->tabpoint == NULL)
		return (-666);
	if (malloc_tab(eve->tabpoint, w, h) == -666)
		return (-666);
	eve->fd = open(argv[1], O_RDONLY);
	eve->limit = parsing(eve->fd, eve->tabpoint) - 1;
	eve->zoom = magic_numbers(h, w);
	eve->image = image;
	eve->mlx = mlx;
	eve->offsetx = 10;
	eve->offsety = 10;
	eve->offsetz = 0;
	eve->anglex = 0.0000000;
	eve->angley = sqrt(3/2);
	eve->anglez = 0.0000000;
	fade_to_black(eve);
	createtab(eve);
	return (0);
}

int	main(int argc, char *argv[])
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_everything	*eve;

	if (argc > 2)
		return (-1);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (mlx_close_window(mlx), \
		puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return (mlx_close_window(mlx), \
		puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	eve = malloc (sizeof(*eve));
	if (ini_eve(eve, argv, image, mlx) == -666)
		return (mlx_terminate(mlx), -666);
	mlx_key_hook(mlx, &my_keyhook, (void *)eve);
	return (mlx_loop(mlx), mlx_terminate(mlx), 0);
}
