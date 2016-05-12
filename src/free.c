/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:35:20 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:33:52 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_room(t_room *room)
{
	free(room->name);
	room->name = NULL;
	free(room);
	room = NULL;
}

void			free_dlist(t_dlist *list)
{
	free(list);
	list = NULL;
}
