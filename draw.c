/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:43:41 by mlapique          #+#    #+#             */
/*   Updated: 2024/06/05 16:34:35 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	printbijour(t_point **tab, int limit)
// {
// 	int	i;
// 	int	j;

// 	printf("debut\n\n");
// 	j = 0;
// 	i = 0;
// 	while (tab[i])
// 	{
// 		while (j < limit)
// 		{
// 			if (tab[i][j].x > WIDTH || tab[i][j].x > 0){
// 			printf("i = %d ", i);
// 			printf("j = %d ", j);
// 			printf("x = %d ", tab[i][j].x);
// 			printf("y = %d ", tab[i][j].y);
// 			printf("z = %d ", tab[i][j].z);
// 			printf("\n\n");
// 			}
// 			j++;
// 		}
// 		printf(" \n \n maintenant new ligne \n\n ");
// 		i++;
// 		j = 0;
// 	}
// }

int	draw_everything(t_point **tabpoint, mlx_image_t *image, int limit)
{
	int					i;
	int					j;
	t_line_necessary	*theline;
	t_point				temp;

	if (limit < 0)
		return (-666);
	theline = malloc(sizeof(t_line_necessary));
	i = 0;
	j = 0;
	// printf("draw everything\n\n");
	// printbijour(tabpoint, limit);
	while (tabpoint[i])
	{
		while (j < limit)
		{
			temp = tabpoint[i][j];
			theline->p1 = temp;
			if (j + 1 < limit)
			{
				temp = tabpoint[i][j + 1];
				theline->p2 = temp;
				line(theline, image);
			}
			temp = tabpoint[i][j];
			theline->p1 = temp;
			if (tabpoint[i + 1] != NULL)
			{
				temp = tabpoint[i + 1][j];
				theline->p2 = temp;
				line(theline, image);
			}
			j++;
		}
		i++;
		j = 0;
	}
	// temp = (t_point){50,500,0,NULL};
	// theline->p1 = temp;
	// temp = (t_point){20,200,0,NULL};
	// theline->p2 = temp;
	// line(theline, image);
	return (10);
}
