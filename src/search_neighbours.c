/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_neighbours.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:19:41 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:39:01 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				search_neighbours(t_anthill *anthill, t_room *room)
{
	t_room			*tmp;

	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room->name))
			room->neighbours = tmp->neighbours;
		tmp = tmp->next;
	}
}
