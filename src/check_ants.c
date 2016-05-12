/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 02:04:08 by pba               #+#    #+#             */
/*   Updated: 2016/05/11 15:43:28 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_ants(t_anthill *anthill, int *flag, char *line)
{
	if (*flag == 0)
	{
		if (!ft_isint(line))
			return (0);
		*flag = 1;
		anthill->ants = ft_atoi(line);
	}
	return (1);
}
