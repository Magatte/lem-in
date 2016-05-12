/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_red_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 23:44:40 by pba               #+#    #+#             */
/*   Updated: 2016/05/11 09:57:56 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_red_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[1;91m", fd);
	write(fd, str, ft_strlen(str));
	ft_putstr_fd("\033[0m", fd);
}