/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:52 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:14:52 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nsize(long n, int size)
{
	if (n < 0)
		return (ft_nsize(-n, size + 1));
	if (n > 0)
		return (ft_nsize(n / 10, size + 1));
	return (size);
}

char	*ft_specials(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	size;
	long	nb;

	nb = n;
	if (n == 0 || n == -2147483648)
		return (ft_specials(n));
	size = ft_nsize(nb, 0);
	itoa = malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (0);
	if (n < 0)
		nb = -n;
	itoa[size] = '\0';
	while (nb > 0)
	{
		itoa[--size] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
/*
#include <stdio.h>
int main(int a, char **v)
{
	char *test = malloc(sizeof(char) * 12);
	printf("%s\n", ft_itoa(atoi(v[1])));
	sprintf(test, "%d", atoi(v[1]));
	printf("%s\n", test);
	free(test);
}*/
