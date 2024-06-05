/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:31:26 by mlapique          #+#    #+#             */
/*   Updated: 2024/06/04 14:02:33 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void afftab(t_point **tabpoint, int limit)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (tabpoint[i])
// 	{
// 		while (j < limit)
// 		{
// 			printf("aff tabpoint\n\nj = %d, x = %d, y = %d, z = %d\n\n", j, tabpoint[i][j].x, tabpoint[i][j].y, tabpoint[i][j].z);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	printf("the end\n\n\n\n");
// 	return ;
// }

int	magic_numbers(width, height)
{
	int	zoom;

	zoom = 40;
	while ((zoom * (width - 1) > (WIDTH - (WIDTH / 100))) || (zoom * (height - 1) > (HEIGHT  - HEIGHT / 100)))
	{
		zoom -= 1;
	}
	if (zoom <= 0)
		return (1);
	return (zoom);
}

int	verif_value(char *value)
{
	int	i;

	i = 0;
	if (!value)
		return (-1000);
	while (value[i])
	{
		if (value[i] == '\n' && i == 0)
			return (-10);
		else if ((value[i] == '-' || value[i] == '+') && i == 0)
			i++;
		if (ft_isdigit(value[i]) == 0 && value[i] != '\n')
			return (-666);
		i++;
	}
	return (1);
}

int	parsing2(t_point **tabpoint, t_parse *parse)
{
	int	limit;

	while (parse->split[parse->j])
	{
		parse->splitcolor = ft_split(parse->split[parse->j], ',');
		if (ft_strlen_for_tab(parse->splitcolor) > 2)
			return (-666);
		if (!parse->splitcolor)
			return (-666);
		if (verif_value(parse->splitcolor[0]) == -666)
			return (-666);
		parse->point->z = ft_atoi(parse->splitcolor[0]);
		parse->point->y = parse->i;
		parse->point->x = parse->j;
		parse->point->color = parse->splitcolor[1];
		tabpoint[parse->i][parse->j] = *parse->point;
		free(parse->point);
		parse->point = malloc(sizeof(t_point));
		if (parse->point == NULL)
			return (-666);
		parse->j++;
	}
	limit = parse->j;
	return (limit);
}

int	parsing(int fd, t_point **tabpoint)
{
	t_parse	*parse;
	int		limit;

	parse = malloc(sizeof(t_parse));
	if (parse == NULL)
		return (-666);
	parse->i = 0;
	parse->j = 0;
	parse->point = malloc(sizeof(t_point));
	if (parse->point == NULL)
		return (-666);
	parse->line = get_next_line(fd);
	if (!parse->line)
		return (-666);
	while (parse->line)
	{
		parse->split = ft_split(parse->line, ' ');
		if (!parse->split)
			return (-666);
		limit = parsing2(tabpoint, parse);
		if (limit == -666)
			return (-666);
		parse->j = 0;
		parse->i++;
		free(parse->line);
		parse->line = get_next_line(fd);
	}
	tabpoint[parse->i] = NULL;
	return (limit);
}
