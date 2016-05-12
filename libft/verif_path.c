/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:38:59 by pba               #+#    #+#             */
/*   Updated: 2015/05/31 18:28:40 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				verif_path(char **env)
{
	int			i;
	int			signal;

	signal = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) != 0 || ft_strlen(env[i]) <= 5)
			i++;
		else
		{
			signal = 1;
			break ;
		}
	}
	return (signal);
}
