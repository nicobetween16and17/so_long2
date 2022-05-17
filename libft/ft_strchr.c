/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:09:46 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 12:09:47 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "tripouille";
	printf("3original\t: %s\n", strchr(s,'z'));
	printf("3mine\t\t: %s\n\n", ft_strchr(s, 'z'));
	printf("5original\t: %s\n", strchr(s, 't'+256));
	printf("5mine\t\t: %s\n", ft_strchr(s, 't' + 256));
}*/