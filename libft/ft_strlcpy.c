/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:34:22 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 13:34:23 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "coucou";
	char dest[10];
	memset(dest, 'A', 10);
	printf("2 original\t: %lu %s\n", strlcpy(dest, src, 1), dest );
	printf("2 mine\t\t: %zu %s\n\n", ft_strlcpy(dest, src, 1), dest);
}*/
