/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:41:15 by pba               #+#    #+#             */
/*   Updated: 2016/05/11 10:20:54 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					is_command(char *line)
{
	if (line && ft_strnequ(line, "##", 2) == 1)
		return (1);
	return (0);
}

int					is_comment(char *line)
{
	if (line && line[0] == '#')
		return (1);
	return (0);
}

int					is_room(char *line)
{
	char			**descript;

	descript = ft_strsplit(line, ' ');
	if (descript && !(is_command(line)) && !(is_comment(line)))
	{
		if (descript[0][0] == 'L')
			return (0);
		if (count_words(descript) != 3)
			return (0);
		if (!(ft_isint(descript[1])) || !(ft_isint(descript[2])))
			return (0);
		return (1);
	}
	return (0);
}

int					is_tube(char *line)
{
	char			**descript;

	descript = ft_strsplit(line, '-');
	if (descript && count_words(descript) == 2
			&& descript[0][0] != '#' && descript[1][0] != '#'
			&& descript[0][0] != 'L' && descript[1][0] != 'L')
		return (1);
	return (0);
}

int					parser(t_anthill *anthill)
{
	char			*line;
	int				se;
	int				flag;

	line = NULL;
	se = 0;
	flag = 0;
	while (get_next_line(0, &line) > 0 && ft_strlen(line) != 0)
	{
		if (flag == 0)
		{
			if (check_ants(anthill, &flag, line) == 0)
				return (0);
		}
		else
		{
			if (check_anthill(line, &se) == 0)
				return (0);
		}
		anthill->lines = push_line(anthill->lines, line);
		ft_putendl(line);
	}
	if (se != 2)
		return (0);
	return (1);
}
