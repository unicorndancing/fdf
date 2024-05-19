/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:06 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/19 16:29:38 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "math.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}		t_point;

typedef struct s_line_necessary
{
	t_point	*p1;
	t_point	*p2;
	float	grad;
	int		first_point;
	int		last_point;
}		t_line_necessary;

typedef struct s_parse
{
	char	*line;
	char	**split;
	int		i;
	int		j;
	char	**splitcolor;
	t_point	*point;

}		t_parse;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}		t_mlx;

void	line(t_line_necessary *line, mlx_t *mlx, mlx_image_t *image);
int		ft_strlen_for_tab(char **tab);

#endif