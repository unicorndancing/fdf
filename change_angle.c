/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2eve->anglez24/eve->anglez6/eve->anglez4 16:32:31 by mlapique          #+#    #+#             */
/*   Updated: 2eve->anglez24/eve->anglez6/eve->anglez5 14:53:27 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(t_everything *eve)
{
	int	i;
	int	j;
	int bijour;

	i = eve->anglez;
	j = eve->anglez;
	while (eve->tabpoint[i])
	{
		while (j < eve->limit)
		{
			bijour = eve->tabpoint[i][j].x;
			eve->tabpoint[i][j].x = (cos(sqrt(eve->anglex)) * ((sin(sqrt(eve->anglex)) * eve->tabpoint[i][j].y) + (cos(sqrt(eve->anglex)) * eve->tabpoint[i][j].x))) - (sin(sqrt(eve->anglex)) * eve->tabpoint[i][j].z);
			bijour = eve->tabpoint[i][j].y;
			eve->tabpoint[i][j].y = (sin(sqrt(eve->angley)) * ((cos(sqrt(eve->angley)) * eve->tabpoint[i][j].z) + (sin(sqrt(eve->angley)) * ((sin(sqrt(eve->angley)) * eve->tabpoint[i][j].y) + (cos(sqrt(eve->angley)) * eve->tabpoint[i][j].x))))) + (cos(sqrt(eve->angley)) * ((cos(sqrt(eve->angley)) * eve->tabpoint[i][j].y) - (sin(sqrt(eve->angley)) * eve->tabpoint[i][j].x))) + bijour;
			bijour = eve->tabpoint[i][j].z;
			eve->tabpoint[i][j].z = (cos(sqrt(eve->anglez)) * ((cos(sqrt(eve->anglez)) * eve->tabpoint[i][j].z) + (sin(sqrt(eve->anglez)) * ((sin(sqrt(eve->anglez)) * eve->tabpoint[i][j].y) + (cos(sqrt(eve->anglez)) * eve->tabpoint[i][j].x))))) - (sin(sqrt(eve->anglez)) * ((cos(sqrt(eve->anglez)) * eve->tabpoint[i][j].y) - (sin(sqrt(eve->anglez)) * eve->tabpoint[i][j].x)));
			j++;
		}
		i++;
		j = eve->anglez;
	}
}
