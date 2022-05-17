/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:23:20 by niespana          #+#    #+#             */
/*   Updated: 2022/05/16 19:23:21 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_printf("endgame\n");
	system("ps -a|grep afplay|grep -v 'grep'|awk '{print $1}'|xargs kill -15");
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	handle_input(keycode, &(vars->map), &(vars->player), vars);
	if ((is_exit(vars->player.cp, vars->map.exits)
			&& vars->player.nb_collectibles == vars->map.nb_collectibles)
		|| keycode == 53)
	{
		end_game(vars->map);
		destroy(keycode, vars);
	}
	return (0);
}
