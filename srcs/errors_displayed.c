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
	ft_printf("Argument error\n");
	return (-1);
}

int	wall_error(void)
{
	ft_printf("hole in the wall error\n");
	return (-1);
}

int	map_error(void)
{
	ft_printf("line size error\n");
	return (-1);
}

int	no_exit_error(void)
{
	ft_printf("No exits error\n");
	return (-1);
}

int	mc_error(void)
{
	ft_printf("Incorrect number of MC error\n");
	return (-1);
}
