/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:14:22 by pba               #+#    #+#             */
/*   Updated: 2016/05/17 20:23:42 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			path_exist(t_anthill *anthill)
{
	t_room			*tmp;

	if (anthill->paths && anthill->paths[0] && anthill->paths[1] == NULL
			&& anthill->paths[0]->size <= 2 && anthill->option_n == 1)
		return (1);
	tmp = anthill->rooms->head;
	while (tmp)
	{
		if (tmp->in_path && tmp->mark != -1 && tmp->mark == anthill->option_n)
			return (1);
		tmp = tmp->next;
	}
	ft_putendl_fd("This path doesn't exist.", 2);
	ft_putchar('\n');
	anthill->option_n = 0;
	return (0);
}

static int			lem_in(t_anthill *anthill)
{
	if (anthill_init(anthill) && anthill->start && anthill->target)
	{
		if (ft_strequ(anthill->start->name, anthill->target->name))
			return (-2);
		set_costs(anthill);
		anthill->paths = find_paths(anthill);
		if (anthill->paths == NULL)
			return (-1);
		set_marks(anthill);
		if (anthill->option_n != INT_MAX)
		{
			if (path_exist(anthill) == 0)
				return (usage());
		}
		return (1);
	}
	else
		ft_putendl_fd("ERROR", 2);
	return (0);
}

static int			lem_in_options(t_anthill *anthill, int ac, char **av)
{
	if (ac == 2)
	{
		if (options_init(anthill, av[1], 2) == 0)
			return (usage());
	}
	else
	{
		if (!anthill->option_s && !anthill->option_v)
			return (usage());
		if (options_init(anthill, av[2], 2) == 0)
			return (usage());
	}
	return (1);
}

static int			check_options(t_anthill *anthill, int ac, char **av)
{
	int				i;

	if (ac == 2 || ac == 3)
	{
		if (av[1][0] == '-' && ft_strlen(av[1]) == 1)
			return (usage());
		i = 1;
		while (av[1][i] && av[1][0] == '-')
		{
			if (av[1][i] != 'v' && av[1][i] != 's')
				return (usage());
			else if (options_init(anthill, &(av[1][i]), 1) == 0)
				return (usage());
			++i;
		}
		if (ac == 2 && !anthill->option_v && !anthill->option_s)
			return (lem_in_options(anthill, ac, av));
		else if (ac == 3)
			return (lem_in_options(anthill, ac, av));
	}
	return (ac > 3) ? usage() : 1;
}

int					main(int ac, char **av)
{
	t_anthill		*anthill;
	int				result;

	anthill = new_anthill();
	if (check_options(anthill, ac, av) == 1)
	{
		if ((result = lem_in(anthill)) == 0)
			return (0);
		ft_putstr_green_fd("Input-file well formated", 2);
		ft_putendl("\n");
		if (anthill->option_v)
			anthill_display(anthill);
		if (result != -1 && result != -2)
			walking(anthill);
		else
		{
			if (result == -2)
				ft_putstr_red_fd("Start room and end room are the same.", 2);
			else
				ft_putstr_red_fd("There's no possible path.", 2);
			ft_putchar('\n');
		}
	}
	return (0);
}
