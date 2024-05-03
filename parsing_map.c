/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:31:26 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/02 18:09:40 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ini_parsing(int fd)
{
	t_point			**map;
	char			*line;
	char			**secondsplit;
	char			**resultsplit;
	int				i;

	i = 0;
	line = get_next_line(fd);
	while (1)
	{
		resultsplit = ft_split(line, ' ');
	}
	write (1, 48, 1);
	return (map);
}
