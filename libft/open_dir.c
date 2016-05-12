/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 10:00:55 by pba               #+#    #+#             */
/*   Updated: 2015/05/31 20:43:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			open_dir(const char *path, int args, t_env *save)
{
	int		result;

	if (args > 1)
	{
		ft_putendl("cd: Too many arguments.");
		return (0);
	}
	if (args <= 0)
		path = save->home;
	if ((strcmp(path, "~") == 0))
		path = save->home;
	if ((strcmp(path, "-") == 0))
		path = save->oldpwd;
	result = chdir(path);
	if (result == 0)
		return (0);
	else
		return (-1);
}
