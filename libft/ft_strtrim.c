/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:31 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:14:32 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	char			*trim;
	size_t			end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end - 1 > 0 && ft_is_set(s1[end - 1], set))
		end--;
	if (start > end)
		end = start;
	end -= start;
	if (!end)
		start = 0;
	trim = ft_substr(s1, start, end);
	return (trim);
}
/*
#include <stdio.h>
int main()
{
	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t\
 			Please\n Trim me !\n   \n \n \t\t\n  ";
	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("%s\n", ret);
	printf("################\n");
	printf("%s\n", s2);
	printf("%d\n", !ft_strncmp(ret, s2, ft_strlen(ret)));
}*/
