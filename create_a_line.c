/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:13 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/03 15:52:45 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_line_necessary line, t_mlx mlx)
{
	float	grad;
	int		i;
	int		godownornot;

	godownornot = steepness(line.p1, line.p2);
	grad = rgrad(line.p1, line.p2);
	line.first_point = partone(line.p1, line.p2, grad, mlx);
	line.last_point = parttwo(line.p1, line.p2, grad, mlx);
	i = line.first_point;
	if (godownornot == 1)
	{
		while (i < line.last_point)
		{
			mlx_put_pixel(mlx.image, );
		}
	}

}


float	rgrad(t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	grad;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0)
		return (1);
	else
		return (dy / dx);
}

int	steepness(t_point p1, t_point p2)
{
	t_point	swap;

	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
	{
		swap = p1;
		p1.x = swap.y;
		p1.y = swap.x;
		swap = p2;
		p2.x = swap.y;
		p2.y = swap.x;
		return (1);
	}
	if (p1.x > p2.x)
	{
		swap = p2;
		p2 = p1;
		p1 = swap;
		return (0);
	}
}

int	partone(t_point p1, t_point p2, float grad, t_mlx mlx)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = round(p1.x);
	yend = p1.y + grad * (xend - p1.x);
	xhole = 1 - floatpart(p1.x + 0.5);
	truc = floor(yend);
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
	{
		mlx_put_pixel(mlx.image, truc, xend, 0xFFFF);
		mlx_put_pixel(mlx.image, truc + 1, xend, 0xFFFF);
	}
	else
	{
		mlx_put_pixel(mlx.image, xend, truc, 0xFFFF);
		mlx_put_pixel(mlx.image, xend, truc + 1 , 0xFFFF);
	}
	return (truc);
}

int	parttwo(t_point p1, t_point p2, float grad, t_mlx mlx)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = round(p2.x);
	yend = p2.y + grad * (xend - p2.x);
	xhole = 1 - floatpart(p2.x + 0.5);
	truc = floor(yend);
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
	{
		mlx_put_pixel(mlx.image, truc, xend, 0xFFFF);
		mlx_put_pixel(mlx.image, truc + 1, xend, 0xFFFF);
	}
	else
	{
		mlx_put_pixel(mlx.image, xend, truc, 0xFFFF);
		mlx_put_pixel(mlx.image, xend, truc + 1 , 0xFFFF);
	}
	return (truc);
}
