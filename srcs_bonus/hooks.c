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

int	destroy(t_vars *vars)
{
	ft_printf("endgame\n");
	system("ps -a|grep afplay|grep -v 'grep'|awk '{print $1}'|xargs kill -15");
	if (vars->dead)
		system("afplay sound/isaac_dies_new.wav ");
	if (vars->flies)
		free(vars->flies);
	if (vars->shits)
		free(vars->shits);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	//system("leaks so_long");
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
		destroy(vars);
	}
	return (0);
}

void	image_moove(t_vars *v, int i, int frame)
{
	v->map.images[4].img = v->sprites[i - 1]->content;
	v->sprites[i - 1] = v->sprites[i - 1]->next;
	if (i - 1 == 0)
		v->map.images[2].img = v->map.images[32].img;
	if (i - 1 == 0)
		v->map.images[3].img = v->map.images[32].img;
	if (i - 1 == 1)
		v->map.images[2].img = v->map.images[41].img;
	if (i - 1 == 1)
		v->map.images[3].img = v->map.images[42].img;
	if (i - 1 == 2)
		v->map.images[2].img = v->map.images[33].img;
	if (i - 1 == 2)
		v->map.images[3].img = v->map.images[34].img;
	if (i - 1 == 3)
		v->map.images[2].img = v->map.images[31].img;
	if (i - 1 == 3)
		v->map.images[3].img = v->map.images[35].img;
	if (frame >= 22)
		v->map.images[4].img = v->map.images[23].img;
}

void	handle_moove(t_vars *v, int i)
{
	if (!v->player.mooving || v->last_frame)
		return ;
	v->player.mooving += 2;
	if (v->direction == UP)
		v->p.x -= 4;
	else if (i++ && v->direction == DOWN)
		v->p.x += 4;
	else if (i++ && v->direction == LEFT)
		v->p.y -= 4;
	else if (i++ && v->direction == RIGHT)
		v->p.y += 4;
	image_moove(v, i, v->player.mooving);
	if (v->player.mooving >= 22)
	{
		v->player.mooving = 0;
	}
}

void	set_vars(t_vars *v)
{
	set_player_pos(v);
	v->tears = NULL;
	v->player.mooving = 0;
	v->timer.h = 0;
	v->timer.m = 0;
	v->timer.s = 0;
	v->time = 0;
	v->event = 0;
	init_all_sprites(v);
	init_cacas(v, v->map.map, 0, 0);
	init_flies(v, v->map.map, 0, 0);
	v->last_pos = -1;
	v->nb_tears = 0;
	v->dead = 0;
}
