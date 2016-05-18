/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:54:28 by pba               #+#    #+#             */
/*   Updated: 2016/05/17 20:28:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			rooms_display(t_anthill *anthill)
{
	t_room			*tmp;

	tmp = anthill->rooms->head;
	while (tmp)
	{
		ft_putstr("Room name : ");
		ft_putendl(tmp->name);
		ft_putstr("Coords : ");
		ft_putnbr(tmp->x);
		ft_putchar(' ');
		ft_putnbr(tmp->y);
		ft_putchar('\n');
		ft_putstr("room ");
		ft_putstr(tmp->name);
		ft_putstr(" cost : ");
		ft_putnbr(tmp->gcost);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void			tubes_display(t_anthill *anthill)
{
	int				i;

	i = 0;
	while (anthill->tubes && anthill->tubes[i])
	{
		ft_putstr("Tube : ");
		ft_putendl(anthill->tubes[i]);
		++i;
	}
	ft_putchar('\n');
}

static void			neighbours_display(t_anthill *anthill)
{
	int				i;
	t_room			*tmp;

	if (!anthill->rooms)
		return ;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		ft_putstr("room ");
		ft_putstr(tmp->name);
		ft_putstr(" detailed : ");
		ft_putstr("mark ( ");
		ft_putnbr(tmp->mark);
		ft_putstr(" ) neighbours ( ");
		i = 0;
		while (tmp->neighbours[i])
		{
			ft_putstr(tmp->neighbours[i]->name);
			ft_putstr(" ");
			++i;
		}
		ft_putendl(")");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void			path_display(t_anthill *anthill)
{
	t_room			*tmp;
	int				i;

	if (!anthill->paths)
		return ;
	ft_putendl("THE PATH(S) : ");
	i = 0;
	while (anthill->paths[i])
	{
		tmp = anthill->paths[i]->head;
		while (tmp->next)
		{
			ft_putstr(tmp->name);
			ft_putstr("->");
			tmp = tmp->next;
		}
		ft_putendl(tmp->name);
		++i;
	}
	ft_putchar('\n');
}

void				anthill_display(t_anthill *anthill)
{
	ft_putstr("Start : room ");
	if (anthill->target)
		ft_putendl(anthill->start->name);
	ft_putstr("End : room ");
	if (anthill->target)
		ft_putendl(anthill->target->name);
	ft_putchar('\n');
	rooms_display(anthill);
	tubes_display(anthill);
	neighbours_display(anthill);
	path_display(anthill);
}
