/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:14 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/19 16:24:19 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen_for_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (-666);
	while (tab[i])
		i++;
	return (i);
}

char	ini(mlx_t *mlx, mlx_image_t *image, char *argv[])
{
	t_point	**tabpoint;
	int		fd;
	int		*i;
	int		*j;

	if (argv[1] == NULL)
		return (-666);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-666);
	tabpoint = malloc((sizeof(t_point ***) * size_map(fd, i, j)) + 1);
	tabpoint = parsing(fd, tabpoint);
	//line(lines, mlx, image);
	return ('0');
}

int	size_map(int fd, int *i, int *j)
{
	char	*line;
	char	**nbpoint;

	line = get_next_line(fd);
	if (!line)
		return (-666);
	i++;
	nbpoint = ft_split(line, ' ');
	if (!nbpoint)
		return (-666);
	j = ft_strlen_for_tab(nbpoint);
	while (line)
	{
		i++;
		free(line);
		free(nbpoint);
		line = get_next_line(fd);
		nbpoint = ft_split(line, ' ');
		if (!nbpoint)
			return (-666);
		if (j != ft_strlen_for_tab(nbpoint))
			return (-666);
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(3000, 1920, "FDF", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	image = mlx_new_image(mlx, 3000, 1920);
	if (!image)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (ini(mlx, image, argv), mlx_loop(mlx), mlx_terminate(mlx), 0);
}
