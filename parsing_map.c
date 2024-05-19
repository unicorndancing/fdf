/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:31:26 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/19 16:34:16 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***parsing2(int fd, t_point ***tabpoint, t_parse *parse)
{
	while (line)
	{
		split = ft_split(line, ' ');
		if (!split)
			return (-666);
		while (split[i])
		{
			splitcolor = ft_split(split[i], ',');
			if (ft_strlen_for_tab(splitcolor) > 2)
				return (-666);
			if (!splitcolor)
				return (-666);
			verify_value(splitcolor[i]);
			point->x = i;
			point->y = j;
			point->z = ft_atoi(splitcolor[0]);
			point->color = splitcolor[1];
			tabpoint[i][j] == point;
			i++;
		}
		i = 0;
		j++;
	}
}

t_point ***parsing(int fd, t_point ***tabpoint)
{
	t_parse	*parse;
	int		i;
	int		j;

	parse = malloc(sizeof(t_parse));
	i = 0;
	j = 0;
	parse->point = malloc(sizeof(t_point));
	parse->line = get_next_line(fd);
	if (!line)
		return (-666);
}

int	verify_value(char *value)
{
	int	i;

	i = 0;
	if (!value)
		return (NULL);
	while (value[i])
	{
		if (ft_isdigit(value[i]) == 0)
			return (-666);
		i++;
	}
	return (1);
}
