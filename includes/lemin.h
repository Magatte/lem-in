/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:42:38 by pba               #+#    #+#             */
/*   Updated: 2016/05/18 17:35:58 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct		s_room
{
	char			*name;
	int				ants;
	int				x;
	int				y;
	int				visited;
	int				in_path;
	int				gcost;
	int				mark;
	struct s_room	*origin;
	struct s_room	*prev;
	struct s_room	*next;
	struct s_room	**neighbours;
}					t_room;
typedef struct		s_dlist
{
	int				size;
	t_room			*head;
	t_room			*tail;
}					t_dlist;
typedef struct		s_tube
{
	t_room			*left;
	t_room			*right;
}					t_tube;
typedef struct		s_anthill
{
	int				ants;
	char			**lines;
	char			**tubes;
	t_dlist			*rooms;
	t_room			*start;
	t_room			*target;
	t_room			*priority;
	t_dlist			*closed;
	int				new_path;
	t_dlist			**paths;
	int				option_v;
	int				option_s;
	int				option_n;
}					t_anthill;
int					usage(void);
int					check_ants(t_anthill *anthill, int *flag, char *line);
int					check_anthill(char *line, int *se);
int					is_command(char *line);
int					is_comment(char *line);
int					is_room(char *line);
int					is_tube(char *line);
int					parser(t_anthill *anthill);
void				push_all_neighbours(t_anthill *anthill);
int					anthill_init(t_anthill *anthill);
int					options_init(t_anthill *anthill, char *option, int mode);
t_room				*new_room(char *name, int x, int y);
t_anthill			*new_anthill(void);
t_dlist				*new_list(void);
t_dlist				*room_append(t_dlist *rooms, char *name, int x, int y);
t_dlist				*room_pop(t_dlist *rooms);
void				search_neighbours(t_anthill *anthill, t_room *room);
void				set_costs(t_anthill *anthill);
void				set_visited(t_anthill *anthill);
void				set_unvisited(t_anthill *anthill);
void				set_in_path(t_anthill *anthill);
t_dlist				*graph_init(t_dlist *rooms);
int					get_min_cost(t_room *current);
t_dlist				**push_path(t_dlist **paths, t_dlist *found_path);
t_dlist				**find_paths(t_anthill *anthill);
void				set_marks(t_anthill *anthill);
int					search_next(t_anthill *anthill, t_room *tmp);
void				init_ants(t_anthill *anthill);
void				write_sequence(t_anthill *anthill, t_room *tmp, int i);
void				walking(t_anthill *anthill);
void				anthill_display(t_anthill *anthill);
void				free_room(t_room *room);
void				free_dlist(t_dlist *list);

#endif
