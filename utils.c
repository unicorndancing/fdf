/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:39:16 by mlapique          #+#    #+#             */
/*   Updated: 2024/05/19 13:42:18 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd(t_point *lst, t_point *new)
{
	t_point	*last;

	if (!lst || !new)
		return ;
	if (lst)
	{
		last = ft_lstlas(lst);
		last->next = new;
	}
	else
		lst = new;
}