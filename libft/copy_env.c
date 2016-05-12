/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:06:14 by pba               #+#    #+#             */
/*   Updated: 2015/05/31 20:06:06 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env				*copy_env(char **env)
{
	t_env			*save;
	int				i;

	save = (t_env*)malloc(sizeof(t_env));
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0 && ft_strlen(env[i]) > 5)
		{
			save->path = ft_strsplit(env[i], '=');
			save->path = ft_strsplit(save->path[1], ':');
		}
		if (strncmp(env[i], "HOME=", 5) == 0 && ft_strlen(env[i]) > 5)
			save->home = ft_strsplit(env[i], '=')[1];
		if (strncmp(env[i], "OLDPWD=", 5) == 0 && ft_strlen(env[i]) > 7)
			save->oldpwd = ft_strsplit(env[i], '=')[1];
		i++;
	}
	return (save);
}
