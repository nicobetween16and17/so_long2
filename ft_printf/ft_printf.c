/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:19:28 by niespana          #+#    #+#             */
/*   Updated: 2022/04/09 13:19:29 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle(char c, va_list arg)
{
	int	res;

	res = 0;
	if (c == '%')
		res = ft_putchar_fd('%', 1, 0);
	if (c == 'c')
		res = ft_putchar_fd((char)va_arg(arg, int), 1, 0);
	if (c == 's')
		res = ft_putstr_fd((char *)va_arg(arg, char *), 1);
	if (c == 'p')
		res = ft_print_ptr((void *)va_arg(arg, void *));
	if (c == 'd' || c == 'i' || c == 'u')
		ft_putnbr_fd((long)va_arg(arg, int), 1, c == 'u', &res);
	if (c == 'x')
		res = ft_print_hex((long)va_arg(arg, long), 0);
	if (c == 'X')
		res = ft_print_hex((long)va_arg(arg, int), 1);
	return (res);
}

int	ft_printf(const char *p, ...)
{
	int		i;
	va_list	arg;
	int		size;

	size = 0;
	va_start(arg, p);
	i = -1;
	if (!p)
		return (-1);
	while (p[++i])
	{
		if (p[i] == '%')
		{
			size += ft_handle(p[i + 1], arg);
			i++;
		}
		else
		{
			ft_putchar_fd(p[i], 1, 0);
			size++;
		}
	}
	va_end(arg);
	return (size);
}
