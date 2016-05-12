/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:09:08 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:39:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		set_priority(t_anthill *anthill, t_room *neighbour, int *j)
{
	anthill->priority = neighbour;
	*j = -2;
}

static int		get_shorter_path(t_anthill *anthill, t_room *tmp)
{
	int			i;
	int			j;
	int			mark;

	mark = -1;
	j = -1;
	i = 0;
	while (tmp->neighbours[i])
	{
		if (tmp->neighbours[i] == anthill->target)
			return (i);
		if (tmp->neighbours[i]->in_path
				&& tmp->neighbours[i]->ants == 0
				&& (mark == -1 || mark > tmp->neighbours[i]->mark))
		{
			mark = tmp->neighbours[i]->mark;
			j = i;
		}
		++i;
	}
	return (j);
}

int				search_next(t_anthill *anthill, t_room *tmp)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (tmp->neighbours[i])
	{
		if (tmp->ants > 0 && (tmp->neighbours[i]->mark == tmp->mark
			|| tmp->mark == -1 || tmp->neighbours[i]->mark == -1)
			&& tmp->neighbours[i]->in_path && tmp->neighbours[i] != tmp->origin
			&& (tmp == anthill->start || tmp->visited == 0))
		{
			if (tmp == anthill->start)
				return (get_shorter_path(anthill, tmp));
			if (tmp->neighbours[i]->ants == 0 ||
					tmp->neighbours[i] == anthill->target)
				return (i);
			if (tmp->mark == tmp->neighbours[i]->mark
					&& tmp->gcost <= tmp->neighbours[i]->gcost)
				set_priority(anthill, tmp->neighbours[i], &j);
		}
		++i;
	}
	return (j == -2) ? -2 : -1;
}
