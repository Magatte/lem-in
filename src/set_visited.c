/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_visited.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 00:40:34 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:41:21 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				set_visited(t_anthill *anthill)
{
	t_dlist			*closed;
	t_room			*tmp;

	closed = anthill->closed;
	closed->tail->visited = 1;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, anthill->closed->tail->name))
			tmp->visited = 1;
		tmp = tmp->next;
	}
}

void				set_in_path(t_anthill *anthill)
{
	t_dlist			*closed;
	t_room			*tmp;
	t_room			*tmp2;

	closed = anthill->closed;
	tmp2 = closed->head;
	while (tmp2->next)
	{
		tmp = anthill->rooms->head;
		while (tmp)
		{
			if (ft_strequ(tmp->name, tmp2->name))
				tmp->in_path = 1;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void				set_unvisited(t_anthill *anthill)
{
	t_room			*tmp;

	tmp = anthill->rooms->head;
	while (tmp)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}
