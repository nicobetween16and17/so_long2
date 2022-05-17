/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:15:02 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:15:03 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmap;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	strmap = ft_strdup(s);
	if (!strmap)
		return (0);
	while (strmap[i])
	{
		strmap[i] = f(i, strmap[i]);
		i++;
	}
	return (strmap);
}
