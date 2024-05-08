/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:14 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/08 16:24:05 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx				mlx;
	t_line_necessary	line_value;

	mlx.mlx = mlx_init(1080, 1920, "FDF", true);
	if (!mlx.mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx.image = mlx_new_image(mlx.mlx, 1080, 1920);
	if (!mlx.image)
	{
		mlx_close_window(mlx.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx.mlx, mlx.image, 0, 0) == -1)
	{
		mlx_close_window(mlx.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	line_value.p1.x = 10;
	line_value.p1.y = 96;
	line_value.p1.z = 0;
	line_value.p1.color = 0;
	line_value.p2.x = 1000;
	line_value.p2.y = 1000;
	line_value.p2.z = 0;
	line_value.p2.color = 0;
	line(line_value, mlx);
	mlx_loop(mlx.mlx);
	mlx_terminate(mlx.mlx);
	return (EXIT_SUCCESS);
}
