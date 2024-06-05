/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:31:26 by mlapique          #+#    #+#             */
/*   Updated: 2024/06/05 17:21:44 by mlapique         ###   ########.fr       */
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

float	floatpart(float x)
{
	return (x - integerpart(x));
}

float	floatipart(float x)
{
	return (1 - floatpart(x));
}

void	steepness_draw_line(t_line_necessary *line, float place \
	, mlx_image_t *image, float grad)
{
	int		i;
	float	usefull;

	i = 0;
	i = line->p1.x + 1;
	while (i < line->p2.x - 1)
	{
		usefull = 1 - (place - floor(place));
		if ((i < HEIGHT - 1 && floor(place) < WIDTH - 1) \
	&& ((i > 0 && floor(place) > 0)))
		{
			mlx_put_pixel(image, i, floor(place), 0x00FFFFFF);
			usefull = (place - floor(place));
			mlx_put_pixel(image, i, floor(place) + 1, 0x00FFFFFF);
		}
		else if (line->p2.x > WIDTH)
			return ;
		place += grad;
		i++;
	}
}
