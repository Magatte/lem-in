/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:01:19 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:41:51 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					usage(void)
{
	ft_putendl_fd("ERROR : invalid options.", 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("Usage : lem_in [-vs] [n] > graph", 2);
	ft_putendl_fd("		-v : verbose mode", 2);
	ft_putendl_fd("		-s : step by step mode", 2);
	ft_putendl_fd("		n : the number of the path to use", 2);
	return (0);
}
