/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 00:07:27 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:42:31 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_dlist			*add_closed_room(t_anthill *anthill, t_room *current,
							int i)
{
	anthill->closed = room_append(anthill->closed, current->neighbours[i]->name,
		current->neighbours[i]->x, current->neighbours[i]->y);
	search_neighbours(anthill, anthill->closed->tail);
	anthill->closed->tail->visited = 1;
	set_visited(anthill);
	return (anthill->closed);
}

static int				check_neighbours(t_anthill *anthill, t_room *current)
{
	int					pos;

	if ((pos = get_min_cost(current)) != -1)
	{
		anthill->closed = add_closed_room(anthill, current, pos);
		if (!ft_strequ(anthill->closed->tail->name, anthill->target->name))
			anthill->new_path = 1;
		return (1);
	}
	return (0);
}

static t_dlist			*deep_search(t_anthill *anthill)
{
	t_dlist				*closed;
	t_room				*current;

	closed = anthill->closed;
	current = closed->tail;
	if (current->neighbours != NULL)
	{
		if (check_neighbours(anthill, current) != 0)
			return (anthill->closed);
	}
	closed = room_pop(closed);
	return (closed);
}

static t_dlist			*find_one_path(t_anthill *anthill)
{
	t_room				*start;

	anthill->closed = new_list();
	start = anthill->start;
	anthill->new_path = 0;
	anthill->closed = room_append(anthill->closed,
			start->name, start->x, start->y);
	search_neighbours(anthill, anthill->closed->tail);
	anthill->closed->tail->visited = 1;
	set_visited(anthill);
	while (anthill->closed)
	{
		if (ft_strequ(anthill->closed->tail->name, anthill->target->name))
		{
			if (anthill->new_path == 0 && anthill->closed->size > 2)
				return (NULL);
			set_in_path(anthill);
			return (anthill->closed);
		}
		anthill->closed = deep_search(anthill);
	}
	return (anthill->closed);
}

t_dlist					**find_paths(t_anthill *anthill)
{
	t_dlist				**paths;
	t_dlist				*found_path;
	int					path_len;

	path_len = INT_MAX - 100;
	paths = anthill->paths;
	while ((found_path = find_one_path(anthill)))
	{
		anthill->rooms = graph_init(anthill->rooms);
		if (found_path->size <= path_len + 1)
		{
			paths = push_path(paths, found_path);
			path_len = found_path->size;
		}
		if (found_path->size == 2)
			break ;
	}
	return (paths);
}
