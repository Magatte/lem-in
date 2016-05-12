/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 05:52:39 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:37:39 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				options_init(t_anthill *anthill, char *option, int mode)
{
	if (mode == 1)
	{
		if (*option == 'v' && anthill->option_v != 1)
		{
			anthill->option_v = 1;
			return (1);
		}
		else if (*option == 's' && anthill->option_s != 1)
		{
			anthill->option_s = 1;
			return (1);
		}
	}
	else if (mode == 2)
	{
		if (ft_isint(option))
		{
			anthill->option_n = ft_atoi(option);
			return (1);
		}
	}
	return (0);
}
