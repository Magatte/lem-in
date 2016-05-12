/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 02:35:28 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:37:03 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room				*new_room(char *name, int x, int y)
{
	t_room			*room;

	if ((room = (t_room *)malloc(sizeof(t_room))))
	{
		room->name = ft_strdup(name);
		room->ants = 0;
		room->x = x;
		room->y = y;
		room->visited = 0;
		room->in_path = 0;
		room->gcost = -1;
		room->mark = 0;
		room->origin = NULL;
		room->prev = NULL;
		room->next = NULL;
		room->neighbours = NULL;
	}
	return (room);
}

t_anthill			*new_anthill(void)
{
	t_anthill		*anthill;

	if ((anthill = (t_anthill *)malloc(sizeof(t_anthill))))
	{
		anthill->ants = 0;
		anthill->lines = NULL;
		anthill->rooms = NULL;
		anthill->start = NULL;
		anthill->target = NULL;
		anthill->priority = NULL;
		anthill->tubes = NULL;
		if (!(anthill->rooms = (t_dlist *)malloc(sizeof(t_dlist))))
			return (NULL);
		anthill->rooms->size = 0;
		anthill->rooms->head = NULL;
		anthill->rooms->tail = NULL;
		anthill->paths = NULL;
		anthill->option_v = 0;
		anthill->option_s = 0;
		anthill->option_n = INT_MAX;
	}
	return (anthill);
}

t_dlist				*new_list(void)
{
	t_dlist			*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_dlist				*room_append(t_dlist *rooms, char *name, int x, int y)
{
	t_room			*newroom;

	if (rooms)
	{
		if (!(newroom = new_room(name, x, y)))
			return (rooms);
		if (rooms->head == NULL)
			rooms->head = newroom;
		else
		{
			newroom->prev = rooms->tail;
			rooms->tail->next = newroom;
		}
		rooms->tail = newroom;
		++rooms->size;
	}
	return (rooms);
}

t_dlist				*room_pop(t_dlist *rooms)
{
	t_room			*tmp;

	if (rooms)
	{
		if (rooms->head->next == NULL)
		{
			free_room(rooms->head);
			free_dlist(rooms);
			return (NULL);
		}
		else
		{
			tmp = rooms->tail;
			rooms->tail = rooms->tail->prev;
			rooms->tail->next = NULL;
			free_room(tmp);
		}
		--rooms->size;
	}
	return (rooms);
}
