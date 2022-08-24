/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_displayed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:59:00 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 12:59:01 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	argument_error(void)
{
	ft_printf("Argument Error\n");
	return (-1);
}

int	wall_error(void)
{
	ft_printf("Hole in the wall Error\n");
	return (-1);
}

int	map_error(void)
{
	ft_printf("Line size Error\n");
	return (-1);
}

int	n_e_error(void)
{
	ft_printf("Error: No exits\n");
	return (1);
}

int	mc_error(void)
{
	ft_printf("Error: No baby\n");
	return (-1);
}
