/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:19:28 by niespana          #+#    #+#             */
/*   Updated: 2022/05/25 12:19:29 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	static int	first;

	nb_flie(map, &nb_flies);
	v->flies = malloc(sizeof(t_fly) * (nb_flies + 1));
	if (!v->flies)
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
				v->flies[i_fly++].hp = 6;
				if (!first++)
					system(v->summon_s_effect);
			}
		}
	}
	v->flies[i_fly].h.x = -1;
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
	v->immune = 0;
}
