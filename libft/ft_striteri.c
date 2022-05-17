/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:16:23 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 11:16:24 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	iter(unsigned int i, char * s) {
	*s += i;
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
/*
#include <stdio.h>
int main()
{
	char s[] = "0000000000";
	ft_striteri(s, iter);
	printf("{%s}\n", s);
}*/
