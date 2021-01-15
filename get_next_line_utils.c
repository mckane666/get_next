/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:26:08 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/08 12:26:15 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd) // remove
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		i++;
	}
	write(fd, str, i);
}

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long int l;

	l = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	if (nb / 10)
	{
		ft_putnbr_fd(l / 10, fd);
	}
	ft_putchar_fd(l % 10 + '0', fd);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
