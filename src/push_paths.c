/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 03:28:30 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:38:41 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_dlist					**push_path(t_dlist **paths, t_dlist *found_path)
{
	int					count;
	t_dlist				**tmp;

	count = 0;
	while (paths && paths[count])
		++count;
	tmp = paths;
	if (!(paths = (t_dlist **)malloc(sizeof(t_dlist *) * (count + 2))))
		return (NULL);
	paths[count + 1] = NULL;
	count = 0;
	while (tmp && tmp[count])
	{
		paths[count] = tmp[count];
		++count;
	}
	paths[count] = found_path;
	free(tmp);
	return (paths);
}
