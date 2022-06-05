/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:39 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 13:05:41 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_image2(t_vars *vars, t_position pos, char c)
{
	if (c == '1' && pos.x == 0)
		return (put_it(vars, pos, 15));
	if (c == '1' && pos.x == vars->map.width - 1)
		return (put_it(vars, pos, 16));
	if (c == '1' && pos.y == 0)
		return (put_it(vars, pos, 13));
	if (c == '1' && pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 14));
	if (c == '1' && put_it(vars, pos, 0))
		return (1);
	if (c == '0')
		return (put_it(vars, pos, 1));
	if (c == 'E' && vars->player.nb_collectibles == vars->map.nb_collectibles)
		return (put_it(vars, pos, 12));
	if (c == 'E' && vars->player.nb_collectibles != vars->map.nb_collectibles)
		return (put_it(vars, pos, 18));
	if (c == 'C')
		return (put_it(vars, pos, 17));
	return (1);
}

int	set_image(t_vars *vars, t_position pos, char c)
{
	put_it(vars, pos, 1);
	if (c == 'P' && vars->last_pos != -1)
		set_image(vars, pos, vars->last_pos);
	if (c == 'P')
		put_it(vars, pos, 27);
	if (c == '1' && pos.x == 0 && pos.y == 0)
		return (put_it(vars, pos, 8));
	if (c == '1' && pos.x == 0 && pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 10));
	if (c == '1' && pos.x == vars->map.width - 1 && pos.y == 0)
		return (put_it(vars, pos, 9));
	if (c == '1' && pos.x == vars->map.width - 1
		&& pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 11));
	return (set_image2(vars, pos, c));
}

void	display_map(t_vars *v)
{
	t_position	pos;

	pos.y = -1;
	while (v->map.map[++pos.y])
	{
		pos.x = -1;
		while (v->map.map[pos.y][++pos.x])
			set_image(v, pos, v->map.map[pos.y][pos.x]);
	}
}

void	handle_input2(int keycode, t_map *map, t_player *player, int *last_pos)
{
	if (keycode == 13)
		map->map[player->cp.x][player->cp.y] = *last_pos;
	if (keycode == 0)
		map->map[player->cp.x][player->cp.y] = *last_pos;
	if (keycode == 2)
		map->map[player->cp.x][player->cp.y] = *last_pos;
	if (keycode == 1)
		map->map[player->cp.x][player->cp.y] = *last_pos;
	map->map[player->cp.x][player->cp.y] = *last_pos;
	if (keycode == 1)
		player->cp.x += 1;
	if (keycode == 0)
		player->cp.y -= 1;
	if (keycode == 2)
		player->cp.y += 1;
	if (keycode == 13)
		player->cp.x -= 1;
	*last_pos = map->map[player->cp.x][player->cp.y];
	if (*last_pos == 'C')
		*last_pos = '0';
}

void	handle_input(int keycode, t_map *map, t_player *player, t_vars *vars)
{
	if (!possible_moove(keycode, map->map, player->cp))
		return ;
	vars->p.x = player->cp.x * 42;
	vars->p.y = player->cp.y * 42;
	handle_input2(keycode, map, player, &(vars->last_pos));
	player->nb_mooves++;
	if (map->map[player->cp.x][player->cp.y] == 'C')
		player->nb_collectibles += 1;
	ft_printf("%de déplaçement\n", player->nb_mooves);
	map->map[player->cp.x][player->cp.y] = 'P';
	display_map(vars);
}
