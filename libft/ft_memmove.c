/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:25:45 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 14:25:52 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*mems1;

	mems1 = (char *)s1;
	if (s1 > s2)
	{
		mems1 += n;
		s2 += n;
		while (n > 0)
		{
			*--mems1 = *(char *)--s2;
			n--;
		}
	}
	else if (s1 < s2)
	{
		while (n-- > 0)
			*mems1++ = *(char *)s2++;
	}
	return (s1);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	ft_memmove(sResult + 1, sResult, 2);
	printf("true %d\n", memcmp(sResult, sResult2, 7));
}*/
