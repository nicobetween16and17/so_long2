/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:18:16 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 16:18:17 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
int main ()
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%d\n",memcmp(s2, s3, 4));
	printf("%d\n",ft_memcmp(s2, s3, 4));
	printf("%d\n",memcmp(s, s2, 0));
	printf("%d\n",ft_memcmp(s, s2, 0));
	printf("%d\n",memcmp(s, s2, 1));
	printf("%d\n",ft_memcmp(s, s2, 1));
	printf("%d\n",memcmp(s2, s, 1));
	printf("%d\n",ft_memcmp(s2, s, 1));
	printf("%d\n",memcmp(s, sCpy, 4));
	printf("%d\n",ft_memcmp(s, sCpy, 4));
}*/
