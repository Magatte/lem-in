/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 23:44:04 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:40:13 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int				check_costs(t_anthill *anthill)
{
	t_room				*tmp;
	int					i;

	i = 0;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (tmp->neighbours[0] != NULL && tmp->gcost == -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void				set_ncosts(t_room *target)
{
	t_room				*tmp;
	int					i;

	tmp = target;
	i = 0;
	while (tmp->neighbours[i])
	{
		if (tmp->neighbours[i]->gcost == -1)
			tmp->neighbours[i]->gcost = tmp->gcost + 1;
		++i;
	}
}

static t_room			*find_next_target(t_room *target)
{
	int					i;

	i = 0;
	while (target->neighbours[i])
	{
		if (target->neighbours[i]->visited == 0)
		{
			target->neighbours[i]->visited = 1;
			break ;
		}
		++i;
	}
	return (target->neighbours[i]);
}

void					set_costs(t_anthill *anthill)
{
	int					i;
	t_room				*target;

	target = anthill->target;
	target->gcost = 0;
	target->visited = 1;
	set_ncosts(target);
	while (!check_costs(anthill) && target)
	{
		i = 0;
		if (!target->neighbours[i])
			target = target->next;
		while (target && target->neighbours[i])
		{
			if (target->neighbours[i]->visited == 0)
				set_ncosts(target->neighbours[i]);
			++i;
		}
		if (target && target->neighbours[0])
			target = find_next_target(target);
	}
	anthill->rooms = graph_init(anthill->rooms);
}
