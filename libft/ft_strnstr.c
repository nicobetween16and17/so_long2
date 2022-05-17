/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:13:33 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 13:13:34 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && i + j < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char * empty = (char*)"";
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	//printf("%s\n",strnstr(haystack, "c", -1));
	//printf("%s\n",ft_strnstr(haystack, "c", -1));
	printf("%s\n",strnstr(haystack, "cd", 8));
	printf("%s\n",ft_strnstr(haystack, "cd", 8));
}*/
