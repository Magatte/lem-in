/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_marks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:47:10 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:40:38 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			search_and_mark(t_anthill *anthill, t_room *room, int mark)
{
	t_room			*tmp;

	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room->name))
		{
			if (tmp == anthill->start || tmp == anthill->target)
				tmp->mark = -1;
			else
				tmp->mark = mark;
			break ;
		}
		tmp = tmp->next;
	}
}

void				set_marks(t_anthill *anthill)
{
	t_room			*tmp;
	int				mark;
	int				i;

	if (!anthill->paths)
		return ;
	i = 0;
	mark = 1;
	while (anthill->paths[i])
	{
		tmp = anthill->paths[i]->head;
		while (tmp)
		{
			search_and_mark(anthill, tmp, mark);
			tmp = tmp->next;
		}
		++mark;
		++i;
	}
}
