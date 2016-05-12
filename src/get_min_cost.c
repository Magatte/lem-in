/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 02:27:52 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:35:55 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					get_min_cost(t_room *current)
{
	int				i;
	int				cost;
	int				flag;
	int				pos;

	cost = INT_MAX;
	flag = 0;
	i = 0;
	while (current->neighbours[i])
	{
		if (!current->neighbours[i]->visited
				&& !current->neighbours[i]->in_path)
		{
			current->neighbours[i]->visited = 1;
			if (cost > current->neighbours[i]->gcost)
			{
				cost = current->neighbours[i]->gcost;
				pos = i;
			}
			flag = 1;
		}
		++i;
	}
	return ((flag == 1) ? pos : -1);
}
