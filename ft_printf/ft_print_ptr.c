/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:29:45 by niespana          #+#    #+#             */
/*   Updated: 2022/04/11 14:29:46 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_ptr(void *s)
{
	unsigned long	res;
	int				res2;

	res2 = 2;
	res = (unsigned long) s;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(res, "0123456789abcdef", &res2);
	return (res2);
}
