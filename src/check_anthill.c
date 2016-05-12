/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 02:44:16 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:32:56 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_anthill(char *line, int *se)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		++(*se);
	if ((ft_strequ(line, "")))
		return (0);
	if (!is_command(line) && !is_comment(line)
				&& !is_room(line) && !is_tube(line))
		return (0);
	return (1);
}
