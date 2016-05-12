/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 08:51:24 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:39:41 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				init_ants(t_anthill *anthill)
{
	t_room			*tmp;

	anthill->start->ants = anthill->ants;
	anthill->target->ants = 0;
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (tmp != anthill->start)
			tmp->ants = 0;
		tmp = tmp->next;
	}
	anthill->target->in_path = 1;
}

void				write_sequence(t_anthill *anthill, t_room *tmp, int i)
{
	if (tmp == anthill->start && tmp->neighbours[i] != anthill->target)
		tmp->neighbours[i]->ants = anthill->ants - tmp->ants + 1;
	else
		tmp->neighbours[i]->ants = (tmp->neighbours[i] == anthill->target) ?
			tmp->neighbours[i]->ants + 1 : tmp->ants;
	ft_putchar('L');
	ft_putnbr(tmp->neighbours[i]->ants);
	ft_putchar('-');
	ft_putstr(tmp->neighbours[i]->name);
	ft_putchar(' ');
	tmp->ants = (tmp == anthill->start) ? tmp->ants - 1 : 0;
	tmp->neighbours[i]->origin = tmp;
	tmp->visited = (tmp == anthill->start) ? 0 : 1;
	tmp->neighbours[i]->visited = 1;
}
