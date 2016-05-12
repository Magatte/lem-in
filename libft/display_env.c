/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 10:48:44 by pba               #+#    #+#             */
/*   Updated: 2015/05/31 21:06:38 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*get_list(char **environ)
{
	int			i;
	t_list		*alst;
	t_list		*new;

	alst = NULL;
	i = 0;
	while (environ[i])
	{
		new = NULL;
		new = ft_lstnew(environ[i], ft_strlen(environ[i]) + 1);
		ft_lstadd(&alst, new);
		i++;
	}
	return (alst);
}

char			**put_tab(t_list *alst)
{
	t_list		*tmp;
	char		**tab;
	int			i;

	tmp = alst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tab = (char**)malloc(sizeof(char*) * (i + 1));
	tab[i] = NULL;
	i = 0;
	while (alst)
	{
		tab[i++] = ft_strdup(alst->content);
		alst = alst->next;
	}
	return (tab);
}

char			**put_env(char **environ)
{
	int			i;

	i = 0;
	while (environ[i])
		ft_putendl(environ[i++]);
	return (environ);
}

char			**ft_setenv(char **environ, char **str)
{
	t_list		*alst;
	t_list		*new;
	t_list		*tmp;

	alst = NULL;
	if (str[1] == NULL)
		return (put_env(environ));
	alst = get_list(environ);
	tmp = alst;
	while (tmp)
	{
		if ((ft_strnequ(tmp->content, str[1], ft_strlen(str[1]))) == 1)
		{
			free(tmp->content);
			tmp->content = ft_strjoin(ft_strjoin(str[1], "="), str[2]);
			return (put_tab(alst));
		}
		tmp = tmp->next;
	}
	new = ft_lstnew(str[1], ft_strlen(str[1]));
	ft_lstadd(&alst, new);
	new->content = ft_strjoin(ft_strjoin(str[1], "="), str[2]);
	free(new);
	return (put_tab(alst));
}

char			**ft_unsetenv(char **environ, char **str)
{
	t_list		*lst;
	t_list		**alst;
	t_list		*tmp;

	if (args(str) < 1)
	{
		ft_putendl("Too few arguments.");
		return (environ);
	}
	lst = get_list(environ);
	alst = &lst;
	while (*alst)
	{
		if ((ft_strnequ((*alst)->content, str[1], ft_strlen(str[1]))) == 1)
		{
			tmp = (*alst)->next;
			ft_lstdelone(alst, ft_lstfree);
			*alst = tmp;
			break ;
		}
		alst = &(*alst)->next;
	}
	return ((environ = put_tab(lst)));
}
