/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:40:10 by niespana          #+#    #+#             */
/*   Updated: 2022/04/09 14:40:10 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_putnbr_base(unsigned long s, char *base, int *res)
{
	if (s >= 16)
	{
		ft_putnbr_base(s / 16, base, res);
		ft_putnbr_base(s % 16, base, res);
	}
	else
	{
		ft_putchar_fd(base[s], 1, res);
	}
	return (res);
}

int	ft_print_hex(unsigned int s, int cas)
{
	const char	*base;
	int			res;

	res = 0;
	base = "0123456789abcdef";
	if (cas)
		base = "0123456789ABCDEF";
	ft_putnbr_base(s, (char *)base, &res);
	return (res);
}
