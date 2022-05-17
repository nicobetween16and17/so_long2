/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:52:04 by niespana          #+#    #+#             */
/*   Updated: 2022/04/12 11:52:04 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar_fd(char c, int fd, int *res)
{
	if (res)
		*res = *res + 1;
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int		res;

	res = 0;
	if (!s)
		return (ft_putstr_fd((char *)"(null)", 1));
	while (s[res])
	{
		ft_putchar_fd(s[res], fd, 0);
		res++;
	}
	return (res);
}

int	ft_putnbr_fd(long n, int fd, int unsign, int *res)
{
	if (unsign)
		n = (unsigned int)n;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd, res);
	}
	if (n >= 10)
	{
		ft_putnbr_fd((long)n / 10, fd, unsign, res);
		ft_putnbr_fd((long)n % 10, fd, unsign, res);
	}
	else
		ft_putchar_fd((long)n + 48, fd, res);
	return (*res);
}
