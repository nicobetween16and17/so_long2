/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:09:30 by niespana          #+#    #+#             */
/*   Updated: 2022/05/04 10:09:32 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_image2(t_vars *vars, t_position pos, char c)
{
	if (c == '1' && pos.x == 0)
		return (put_it(vars, pos, 23));
	if (c == '1' && pos.x == vars->map.width - 1)
		return (put_it(vars, pos, 24));
	if (c == '1' && pos.y == 0)
		return (put_it(vars, pos, 21));
	if (c == '1' && pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 22));
	if (c == '1' && put_shit(vars, pos, -1))
		return (1);
	if (c == 'M')
		return (put_it(vars, pos, 48));
	if (c == '0')
		return (put_it(vars, pos, 3));
	if (c == 'E' && vars->player.nb_collectibles == vars->map.nb_collectibles)
		return (put_it(vars, pos, 20));
	if (c == 'E' && vars->player.nb_collectibles != vars->map.nb_collectibles)
		return (put_it(vars, pos, 26));
	if (c == 'C')
		return (put_it(vars, pos, 25));
	return (1);
}

int	set_image(t_vars *vars, t_position pos, char c)
{
	srand((unsigned int)(-1 * (long)&pos.x));
	put_it(vars, pos, 3);
	if (c == 'P' && vars->last_pos != -1)
		set_image(vars, pos, vars->last_pos);
	if (c == '1' && pos.x == 0 && pos.y == 0)
		return (put_it(vars, pos, 16));
	if (c == '1' && pos.x == 0 && pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 18));
	if (c == '1' && pos.x == vars->map.width - 1 && pos.y == 0)
		return (put_it(vars, pos, 17));
	if (c == '1' && pos.x == vars->map.width - 1
		&& pos.y == vars->map.height - 1)
		return (put_it(vars, pos, 19));
	return (set_image2(vars, pos, c));
}

void	display_map(t_vars *v, char **map)
{
	t_position	pos;

	handle_moove(v, 1);
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
			set_image(v, pos, map[pos.y][pos.x]);
	}
	put_hp(v);
	put_timer(v);
	v->t = 0;
	put_mooves(v->player.nb_mooves, v);
	mlx_put_image_to_window(v->mlx, v->win, v->map.images[9].img,
		v->p.y + 6, v->p.x + 20);
	mlx_put_image_to_window(v->mlx, v->win, v->map.images[7].img,
		v->p.y + 6, v->p.x);
	enemies_travel(v, mlx_put_image_to_window);
	tear_travel(v, mlx_put_image_to_window);
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
	static int	final_sound;

	firing(keycode, vars);
	if (!possible_moove(keycode, map->map, player->cp) || player->mooving)
		return ;
	vars->p.x = player->cp.x * 42;
	vars->p.y = player->cp.y * 42;
	handle_input2(keycode, map, player, &(vars->last_pos));
	set_direction(vars, keycode);
	player->nb_mooves++;
	if (map->map[player->cp.x][player->cp.y] == 'C')
	{
		player->nb_collectibles += 1;
		system("afplay sound/penny_pickup_1.wav &");
	}
	player->mooving++;
	ft_printf("%de déplaçement\n", player->nb_mooves);
	map->map[player->cp.x][player->cp.y] = 'P';
	if (map->nb_collectibles == player->nb_collectibles && !final_sound++)
		system("afplay sound/golden_key.wav &");

}
