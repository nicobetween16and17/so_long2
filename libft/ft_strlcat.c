/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:26:13 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 13:26:14 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen((const char *)dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (size + srclen);
	while (src[i] != '\0' && i + dstlen + 1 < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char dest[30];
	memset(dest, 0, 30);
	char dest1[30];
	memset(dest1, 0, 30);
	char *src = (char *)"AAAAAAAAA";
	printf("srclen = %zu\n", ft_strlen(src));
	printf("dstlen = %zu\n", ft_strlen(dest));
	printf("3 %lu  %s\n",strlcat(dest1, src, 3),dest1);
	printf("3 %lu  %s\n",ft_strlcat(dest, src, 3),dest);
	printf("4 %lu %s\n",strlcat(dest1, src, 6),dest1);
	printf("4 %lu %s\n",ft_strlcat(dest, src, 6),dest);
	//printf("5 %d\n",strlcat(dest1, src, -1));
	//printf("5 %lu\n",ft_strlcat(dest, src, -1));
	printf("6 %lu %s\n",strlcat(dest1, src, 17),dest1);
	printf("6 %lu %s\n",ft_strlcat(dest, src, 17),dest);
	printf("7 %lu %s\n",strlcat(dest1, src, 1),dest1);
	printf("7 %lu %s\n",ft_strlcat(dest, src, 1),dest);
	printf("13 %lu %s\n",strlcat(dest1, "123", 1),dest1);
	printf("13 %lu %s\n",ft_strlcat(dest, "123", 1),dest);
	printf("14 %lu %s\n",strlcat(dest1, "123", 2),dest1);
	printf("14 %lu %s\n",ft_strlcat(dest, "123", 2),dest);
	printf("15 %lu %s\n",strlcat(dest1, "123", 3),dest1);
	printf("15 %lu %s\n",ft_strlcat(dest, "123", 3),dest);

}*/
