/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:03:55 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:41:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			move_by_cost(t_anthill *anthill, int cost)
{
	t_room			*tmp;
	int				i;
	int				flag;

	i = 0;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		flag = 0;
		if (tmp->in_path && tmp->gcost == cost && tmp != anthill->target)
		{
			while ((i = search_next(anthill, tmp)) >= 0)
				write_sequence(anthill, tmp, i);
			if (i == -2)
			{
				while ((i = search_next(anthill, anthill->priority)) >= 0)
					write_sequence(anthill, anthill->priority, i);
				flag = 1;
			}
		}
		tmp = (flag == 0) ? tmp->next : tmp;
	}
}

static void			move_forward(t_anthill *anthill, int cost)
{
	int				max_cost;

	max_cost = anthill->start->gcost + 10;
	while (cost <= max_cost)
	{
		set_unvisited(anthill);
		move_by_cost(anthill, cost);
		++cost;
	}
}

static void			handle_s(t_anthill *anthill, int *cost)
{
	char			buf[2];

	while (anthill->target->ants < anthill->ants && read(1, buf, 1))
	{
		buf[1] = '\0';
		if (ft_strequ(buf, "\n"))
		{
			move_forward(anthill, *cost);
			--(*cost);
		}
	}
	ft_putchar('\n');
}

static void			handle_n(t_anthill *anthill)
{
	t_room			*tmp;
	int				n;

	n = anthill->option_n;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (tmp->mark != -1 && tmp->mark != n)
			tmp->in_path = 0;
		tmp = tmp->next;
	}
}

void				walking(t_anthill *anthill)
{
	int				cost;

	init_ants(anthill);
	if (anthill->ants > 0)
		ft_putstr_blue_fd("Ants walking...", 1);
	else
		ft_putstr_red_fd("There's no ants.", 2);
	cost = anthill->start->gcost + 1;
	if (anthill->option_n != INT_MAX)
		handle_n(anthill);
	if (anthill->option_s == 0)
		ft_putchar('\n');
	while (anthill->target->ants < anthill->ants)
	{
		if (anthill->option_s)
			handle_s(anthill, &cost);
		else
		{
			move_forward(anthill, cost);
			ft_putchar('\n');
			--cost;
		}
	}
}
