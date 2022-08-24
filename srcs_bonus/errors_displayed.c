/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displayed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:17:49 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 16:17:50 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	argument_error(void)
{
	ft_printf("Error: argument invalid\n");
	return (-1);
}

int	wall_error(void)
{
	ft_printf("Error: hole in the wall\n");
	return (-1);
}

int	map_error(void)
{
	ft_printf("Error: line size\n");
	return (-1);
}

int	n_e_error(void)
{
	ft_printf("Error: No exits\n");
	return (1);
}

int	mc_error(void)
{
	ft_printf("Error: Baby not found\n");
	return (-1);
}
