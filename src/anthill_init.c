/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:51:21 by pba               #+#    #+#             */
/*   Updated: 2016/05/17 20:29:10 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			room_init(t_anthill *anthill)
{
	int				i;
	int				flag;
	char			**descript;

	flag = 0;
	i = 0;
	while (anthill->lines && anthill->lines[i])
	{
		if (is_room(anthill->lines[i]))
		{
			descript = ft_strsplit(anthill->lines[i], ' ');
			room_append(anthill->rooms, descript[0],
					ft_atoi(descript[1]), ft_atoi(descript[2]));
			if (flag == 1)
				anthill->start = anthill->rooms->tail;
			else if (flag == 2)
				anthill->target = anthill->rooms->tail;
		}
		flag = 0;
		if (ft_strequ(anthill->lines[i], "##start"))
			flag = 1;
		else if (ft_strequ(anthill->lines[i], "##end"))
			flag = 2;
		++i;
	}
}

static void			tube_init(t_anthill *anthill)
{
	int				i;

	i = 0;
	while (anthill->lines && anthill->lines[i])
	{
		if (is_tube(anthill->lines[i]))
			anthill->tubes = push_line(anthill->tubes, anthill->lines[i]);
		++i;
	}
}

static int			search_tube(t_anthill *anthill, char *room)
{
	t_room			*tmp;

	if (!anthill->rooms)
		return (0);
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int			parse_tubes(t_anthill *anthill)
{
	int				i;
	char			**descript;

	i = 0;
	while (anthill->tubes && anthill->tubes[i])
	{
		descript = ft_strsplit(anthill->tubes[i], '-');
		if (!search_tube(anthill, descript[0])
				|| !search_tube(anthill, descript[1]))
			return (0);
		++i;
	}
	return (1);
}

int					anthill_init(t_anthill *anthill)
{
	if (parser(anthill) == 0)
		return (0);
	ft_putchar('\n');
	room_init(anthill);
	tube_init(anthill);
	if (parse_tubes(anthill) == 0)
		return (0);
	push_all_neighbours(anthill);
	return (1);
}
