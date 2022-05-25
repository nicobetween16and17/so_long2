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

		usleep(200000);
		end_game(vars->map);
		destroy(keycode, vars);
	}
	return (0);
}
void	image_moove(t_vars *v, int i, int frame)
{
	v->map.images[9].img = v->sprites[i - 1]->content;
	v->sprites[i - 1] = v->sprites[i - 1]->next;
	if (i - 1 == 0)
		v->map.images[7].img = v->map.images[40].img;
	if (i - 1 == 0)
		v->map.images[8].img = v->map.images[40].img;
	if (i - 1 == 1)
		v->map.images[7].img = v->map.images[49].img;
	if (i - 1 == 1)
		v->map.images[8].img = v->map.images[50].img;
	if (i - 1 == 2)
		v->map.images[7].img = v->map.images[41].img;
	if (i - 1 == 2)
		v->map.images[8].img = v->map.images[42].img;
	if (i - 1 == 3)
		v->map.images[7].img = v->map.images[39].img;
	if (i - 1 == 3)
		v->map.images[8].img = v->map.images[43].img;
	if (frame >= 22)
		v->map.images[9].img = v->map.images[31].img;
}

void	handle_moove(t_vars *v, int i)
{
	if (!v->player.mooving)
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
		v->player.mooving = 0;

}

void	nb_shit(t_vars *v, char **map, int *nb_shits)
{
	t_position	pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == '1' && pos.y != 0 && pos.x != 0
				&& pos.x != v->map.width && pos.y != v->map.height)
				(*nb_shits)++;
		}
	}
}

void	init_cacas(t_vars *v, char **map, int nb_shits, int i_shit)
{
	t_position	pos;

	nb_shit(v, map, &nb_shits);
	v->shits = malloc(sizeof(t_caca) * (nb_shits + 1));
	if (!nb_shits)
		return ;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == '1' && pos.y != 0 && pos.x != 0
				&& pos.x != v->map.width && pos.y != v->map.height)
			{
				v->shits[i_shit].p = pos;
				v->shits[i_shit++].state = 5;
			}
		}
	}
	v->shits[i_shit].p.x = -1;

}

void	nb_flie(char **map, int *nb_flies)
{
	t_position	pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == 'A')
				(*nb_flies)++;
		}
	}
}

void	init_flies(t_vars *v, char **map, int nb_flies, int i_fly)
{
	t_position	pos;

	nb_flie(map, &nb_flies);
	v->flies = malloc(sizeof(t_fly) * (nb_flies + 1));
	if (!nb_flies)
		return ;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == 'A')
			{
				v->flies[i_fly].p = pos;
				v->flies[i_fly].h = new_pos(pos.x * 42, pos.y * 42);
				v->flies[i_fly++].hp = 5;
			}
		}
	}
	v->flies[i_fly].hp = -1;

}

void	set_player_pos(t_vars *v)
{
	int	i;
	int	j;

	i = -1;
	while (v->map.map[++i])
	{
		j = -1;
		while (v->map.map[i][++j])
		{
			if (v->map.map[i][j] == 'P')
			{
				v->player.cp = new_pos(i, j);
				v->p = new_pos(42 * i, 42 * j);
			}
		}
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
}
