/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:39:16 by mlapique          #+#    #+#             */
/*   Updated: 2024/06/05 16:56:50 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void afftab(t_point **tabpoint, int limit)
{
	// int i = 0;
	// int j = 0;

	// while (tabpoint[i])
	// {
	// 	while (j < limit)
	// 	{
			printf("aff tabpoint\n\nj = %d, i = %d, x = %d, y = %d, z = %d\n\n", 0, 0, tabpoint[0][0].x, tabpoint[0][0].y, tabpoint[0][0].z);
		// 	j++;
		// }
	// 	j = 0;
	// 	i++;
	// }
	printf("the end\n\n\n\n");
	return ;
}

void	createtab(t_everything *eve)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (eve->tabpoint[i])
	{
		while (j < eve->limit)
		{
			if (eve->zoom <= 0)
				eve->zoom = 1;
			eve->tabpoint[i][j].x = j * eve->zoom - (eve->tabpoint[i][j].z * eve->offsetz) + eve->offsetx;
			eve->tabpoint[i][j].y = i * eve->zoom - (eve->tabpoint[i][j].z * eve->offsetz) + eve->offsety;
			j++;
		}
		j = 0;
		i++;
	}
	afftab(eve->tabpoint, eve->limit);
	change_angle(eve);
	afftab(eve->tabpoint, eve->limit);
	draw_everything(eve->tabpoint, eve->image, eve->limit);
}

void	recreatetab_after_verif(t_point **tabpoint, \
	int minx, int miny, int limit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tabpoint[i])
	{
		while (j < limit)
		{
			tabpoint[i][j].x += abs(minx);
			tabpoint[i][j].y += abs(miny);
			j++;
		}
		j = 0;
		i++;
	}
}

int		verif_tab(t_point **tabpoint, int limit)
{
	int	i;
	int	j;
	int	minx;
	int	miny;

	i = 0;
	j = 0;
	minx = 0;
	miny = 0;
	if (limit == -666)
		return (-666);
	while (tabpoint[i])
	{
		while (j < limit)
		{
			if (tabpoint[i][j].x < 0 && tabpoint[i][j].x < minx)
				minx = tabpoint[i][j].x;
			if (tabpoint[i][j].y < 0 && tabpoint[i][j].y < miny)
				miny = tabpoint[i][j].y;
			j++;
		}
		j = 0;
		i++;
	}
	if (minx < 0 || miny < 0)
		recreatetab_after_verif(tabpoint, minx, miny, limit);
	return (limit);
}
