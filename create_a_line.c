/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a_line->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:13 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/09 14:21:12 by mlapique         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	integerpart(float x)
{
	return (floor(x));
}

int	roundbottom(float x)
{
	return (floor(x + 0.5));
}

float floatpart(float x)
{
	return (x - integerpart(x));
}

float	floatipart(float x)
{
	return (1 - floatpart(x));
}

float	rgrad(t_line_necessary *line)
{
	float		dx;
	float		dy;
	float		grad;

	dx = line->p2->x - line->p1->x;
	dy = line->p2->y - line->p1->y;
	if (dx == 0)
		return (1);
	else
		return (dy / dx);
}

int	steepness(t_line_necessary *line)
{
	t_point	*swap;

	if (abs(line->p2->y - line->p1->y) > abs(line->p2->x - line->p1->x))
	{
		swap = line->p1;
		line->p1->x = swap->y;
		line->p1->y = swap->x;
		swap = line->p2;
		line->p2->x = swap->y;
		line->p2->y = swap->x;
		return (1);
	}
	if (line->p1->x > line->p2->x)
	{
		swap = line->p2;
		line->p2 = line->p1;
		line->p1 = swap;
		return (0);
	}
	return (2);
}

float	partone(t_line_necessary *line, float grad, mlx_t *mlx, mlx_image_t *image)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = line->p1->x;
	yend = line->p1->y + grad * (xend - line->p1->x);
	xhole = floatipart(line->p1->x + 0.5);
	truc = floor(yend);
	if (abs(line->p2->y - line->p1->y) > abs(line->p2->x - line->p1->x))
	{
		mlx_put_pixel(image, truc, xend, 0xFF0000FF);
		mlx_put_pixel(image, truc + 1, xend, 0xFF0000FF);
	}
	else
	{
		mlx_put_pixel(image, xend, truc, 0xFF0000FF);
		mlx_put_pixel(image, xend, truc + 1, 0xFF0000FF);
	}
	return (yend + grad);
}

int	parttwo(t_line_necessary *line, float grad, mlx_t *mlx, mlx_image_t *image)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = line->p2->x;
	yend = line->p2->y + grad * (xend - line->p2->x);
	xhole = floatipart(line->p2->x + 0.5);
	truc = floor(yend);
	if (abs(line->p2->y - line->p1->y) > abs(line->p2->x - line->p1->x))
	{
		mlx_put_pixel(image, truc, xend, 0xFF0000FF);
		mlx_put_pixel(image, truc + 1, xend, 0xFF0000FF);
	}
	else
	{
		mlx_put_pixel(image, xend, truc, 0xFF0000FF);
		mlx_put_pixel(image, xend, truc + 1 , 0xFF0000FF);
	}
	return (truc);
}

void	line(t_line_necessary *line, mlx_t *mlx, mlx_image_t *image)
{
	float	grad;
	int		i;
	int		godownornot;
	float	place;
	float	usefull;

	godownornot = steepness(line);
	grad = rgrad(line);
	place = partone(line, grad, mlx, image);
	line->last_point = parttwo(line, grad, mlx, image);
	i = line->p1->x + 1;
	if (godownornot == 1)
	{
		while (i < line->p2->x - 1)
		{
			usefull = 1 - (place - floor(place));
			mlx_put_pixel(image, floor(place), i, 0xFFFFFFFF);
			usefull = (place - floor(place));
			mlx_put_pixel(image, floor(place) + 1, i, 0xFFFFFFFF);
			place += grad;
			i++;
		}
	}
	else
	{
		while (i < line->p2->x - 1)
		{
			usefull = 1 - (place - floor(place));
			mlx_put_pixel(image, i, floor(place), 0xFFFFFFFF);
			usefull = (place - floor(place));
			mlx_put_pixel(image, i, floor(place) + 1, 0xFFFFFFFF);
			place += grad;
			i++;
		}
	}
}
