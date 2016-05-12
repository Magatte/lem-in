/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:31:03 by pba               #+#    #+#             */
/*   Updated: 2015/05/31 20:54:01 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_exec_cmd(char *line, char **env, char **path, t_env *save)
{
	char		**comd;

	comd = ft_strsplit(line, ' ');
	if ((ft_builtins(comd, &env, path, save)) == 1)
		return (env);
	else if ((ft_binary(path, comd, env)) == 0)
	{
		write(2, "\033[31;01mzsh : comd not found : \033[33;01m", 39);
		ft_putendl(line);
		exit(0);
	}
	return (env);
}

char			**ft_multi_exec(char *line, char **env,
								char **path, t_env *save)
{
	char		**cmds;
	int			i;

	i = 0;
	while (line[i + 1])
	{
		if (line[i] == ';' && line[i + 1] == ';')
			line[i + 1] = ' ';
		i++;
	}
	cmds = ft_strsplit(line, ';');
	i = 0;
	while (cmds[i])
	{
		if (cmds[i][0] != ' ' || cmds[i][1] != '\0')
			env = ft_exec_cmd(cmds[i], env, path, save);
		i++;
	}
	return (env);
}

void			path_binary(char **path, char **av, char **env)
{
	char		*tmp;
	char		*cmd;
	int			i;

	cmd = av[0];
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		if ((!access(tmp, X_OK)) || (!access(cmd, X_OK)))
		{
			execve(tmp, av, env);
			execve(cmd, av, env);
		}
		i++;
		free(tmp);
	}
}
