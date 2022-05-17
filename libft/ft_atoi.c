/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:37:35 by niespana          #+#    #+#             */
/*   Updated: 2022/04/04 13:37:36 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			signe;
	long		res;

	res = 0;
	signe = 1;
	while (*str != '\0')
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-')
			signe = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			res = (10 * res) + ((*str++) - 48);
			if (signe == 1 && res > 2147483647)
				return (-1);
			if (signe == -1 && res > 2147483648)
				return (0);
		}
		while (*str != '\0')
			str++;
	}
	return ((int)(res * signe));
}
