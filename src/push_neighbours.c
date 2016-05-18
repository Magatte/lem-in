/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:46:31 by pba               #+#    #+#             */
/*   Updated: 2016/05/17 20:20:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			count_neighbours(char **tubes, t_room *room)
{
	int				count;
	int				i;
	char			**str;

	count = 0;
	i = 0;
	while (tubes && tubes[i])
	{
		str = ft_strsplit(tubes[i], '-');
		if (!ft_strequ(str[0], str[1]) && (ft_strequ(str[0], room->name)
				|| ft_strequ(str[1], room->name)))
			++count;
		++i;
	}
	return (count);
}

static t_room		*find_room(t_anthill *anthill, char *room_name)
{
	t_room			*tmp;

	if (!anthill->rooms)
		return (NULL);
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (ft_strequ(room_name, tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

static void			push_neighbours(t_anthill *anthill, t_room *room)
{
	int				count;
	int				i;
	int				j;
	char			**str;

	count = count_neighbours(anthill->tubes, room);
	if (!(room->neighbours = (t_room **)malloc(sizeof(t_room *) * (count + 1))))
		return ;
	room->neighbours[count] = NULL;
	i = 0;
	j = 0;
	while (anthill->tubes && anthill->tubes[i])
	{
		str = ft_strsplit(anthill->tubes[i++], '-');
		if (!ft_strequ(str[0], str[1]) && ft_strequ(str[0], room->name))
		{
			room->neighbours[j] = find_room(anthill, str[1]);
			++j;
		}
		else if (!ft_strequ(str[0], str[1]) && ft_strequ(str[1], room->name))
		{
			room->neighbours[j] = find_room(anthill, str[0]);
			++j;
		}
	}
}

void				push_all_neighbours(t_anthill *anthill)
{
	t_room			*tmp;

	if (!anthill->rooms)
		return ;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		push_neighbours(anthill, tmp);
		tmp = tmp->next;
	}
}
