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

float	rgrad(t_line_necessary *line)
{
	float		dx;
	float		dy;

	dx = line->p2.x - line->p1.x;
	dy = line->p2.y - line->p1.y;
	if (dx == 0)
		return (1);
	else
		return (dy / dx);
}

int	steepness(t_line_necessary *line)
{
	t_point	swap;
	int		steep;

	steep = 1000;
	if (abs(line->p2.y - line->p1.y) > abs(line->p2.x - line->p1.x))
	{
		swap = line->p1;
		line->p1.x = swap.y;
		line->p1.y = swap.x;
		swap = line->p2;
		line->p2.x = swap.y;
		line->p2.y = swap.x;
		steep = 1;
	}
	if (line->p1.x > line->p2.x)
	{
		swap = line->p2;
		line->p2 = line->p1;
		line->p1 = swap;
		if (steep != 1)
			steep = 0 ;
	}
	return (steep);
}

float	partone(t_line_necessary *line, float grad, mlx_image_t *image, int steep)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = line->p1.x;
	yend = line->p1.y + grad * (xend - line->p1.x);
	xhole = floatipart(line->p1.x + 0.5);
	truc = floor(yend);
	if (steep == 1)
	{
		if ((truc + 1 < HEIGHT - 1 && xend < WIDTH - 1) && ((truc > 0 && xend > 0)))
		{
			mlx_put_pixel(image, truc, xend, 0xFF00FFFF);
			mlx_put_pixel(image, truc + 1, xend, 0xFF00FFFF);
		}
	}
	else
	{
		if ((truc + 1 < WIDTH - 1 && xend < HEIGHT - 1) && ((truc > 0 && xend > 0)))
		{
			mlx_put_pixel(image, xend, truc, 0xFF00FFFF);
			mlx_put_pixel(image, xend, truc + 1, 0xFF00FFFF);
		}
	}
	(void)image;
	return (yend + grad);
}

void	parttwo(t_line_necessary *line, float grad, mlx_image_t *image, int steep)
{
	int	xend;
	int	yend;
	int	xhole;
	int	truc;

	xend = line->p2.x;
	yend = line->p2.y + grad * (xend - line->p2.x);
	xhole = floatipart(line->p2.x + 0.5);
	truc = floor(yend);
	if (steep == 1)
	{
		if ((truc + 1 < HEIGHT - 1 && xend < WIDTH - 1) && ((truc > 0 && xend > 0)))
		{
			mlx_put_pixel(image, truc, xend, 0xFF00FFFF);
			mlx_put_pixel(image, truc + 1, xend, 0xFF00FFFF);
		}
	}
	else
	{
		if ((truc + 1 < WIDTH - 1 && xend < HEIGHT - 1) && ((truc > 0 && xend > 0)))
		{
			mlx_put_pixel(image, xend, truc, 0xFF00FFFF);
			mlx_put_pixel(image, xend, truc + 1, 0xFF00FFFF);
		}
	}
}

void	line(t_line_necessary *line, mlx_image_t *image)
{
	float	grad;
	int		i;
	int		steep;
	float	place;
	float	usefull;

	steep = steepness(line);
	grad = rgrad(line);
	place = partone(line, grad, image, steep);
	parttwo(line, grad, image, steep);
	i = line->p1.x + 1;
	if (steep == 1)
	{
		while (i < line->p2.x - 1)
		{
			usefull = 1 - (place - floor(place));
			if ((i < WIDTH - 1 && floor(place) < HEIGHT - 1) && ((i > 0 && floor(place) > 0)))
			{
				mlx_put_pixel(image, floor(place), i, 0x00FFFFFF);
				usefull = (place - floor(place));
				mlx_put_pixel(image, floor(place) + 1, i, 0x00FFFFFF);
			}
			else if (line->p2.x > HEIGHT)
				return ;
			place += grad;
			i++;
		}
	}
	else
		steepness_draw_line(line, place, image, grad);
}
