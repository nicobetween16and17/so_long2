/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:42 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:14:42 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *s, char c, int j)
{
	size_t	i;

	i = 0;
	while (s[j + i] != c && s[j + i])
		i++;
	return (i + 1);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s != c && *s)
		{
			i++;
			while (*(s + 1) != c && *(s + 1))
				s++;
		}
		s++;
	}
	return (i);
}

char	**ft_free_all(char **split, int start)
{
	while (start >= 0)
		free(split[start--]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		k;

	i = -1;
	k = 0;
	if (!s)
		return (0);
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (s[++i])
	{
		if ((!ft_strncmp(s, &s[i], ft_strlen(s)) || s[i - 1] == c) && s[i] != c)
		{
			split[k] = malloc((ft_wordlen(s, c, i) + 1) * sizeof(char));
			if (!split[k])
				return (ft_free_all(split, k));
			ft_strlcpy(split[k++], &s[i], ft_wordlen(s, c, i));
		}
	}
	split[k] = 0;
	return (split);
}
/*
#include <stdio.h>
int main()
{
	int i;

	i = -1;
	char *s = "tripouille";
	//printf("test %d\n",!ft_strncmp(s, &s[0], ft_strlen(s)));
	char **tab = ft_split("tripouille", '0');
	while (tab[++i])
		printf("{%s}\n", tab[i]);
}*/