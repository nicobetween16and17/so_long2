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

#include "../includes/so_long.h"

int	set_image2(t_vars *v, t_position pos, char c)
{
	if (c == 'M')
		return (put_it(v, pos, 40));
	if (c == '0')
		return (put_it(v, pos, 1));
	if (c == 'E' && v->mum.hp <= 0)
		return (put_it(v, pos, 12));
	if (c == 'E' && v->mum.hp > 0)
		return (put_it(v, pos, 18));
	if (c == 'C')
		return (put_it(v, pos, 17));
	return (1);
}

int	set_image(t_vars *v, t_position pos, char c)
{
	if (c == '1' && pos.x != 0 && pos.x != v->map.width - 1 && pos.y != 0 && pos.y != v->map.height - 1)
		put_shit(v, pos, -1);
	put_it(v, pos, 1);
	if (c == 'P' && v->last_pos != -1)
		set_image(v, pos, v->last_pos);
	if (c == '1' && pos.x == 0)
		put_it(v, pos, 15);
	else if (c == '1' && pos.x == v->map.width - 1)
		put_it(v, pos, 16);
	else if (c == '1' && pos.y == 0)
		put_it(v, pos, 13);
	else if (c == '1' && pos.y == v->map.height - 1)
		put_it(v, pos, 14);
	if (c == '1' && pos.x == 0 && pos.y == 0)
		put_it(v, pos, 8);
	if (c == '1' && pos.x == 0 && pos.y == v->map.height - 1)
		put_it(v, pos, 10);
	if (c == '1' && pos.x == v->map.width - 1 && pos.y == 0)
		put_it(v, pos, 9);
	if (c == '1' && pos.x == v->map.width - 1
		&& pos.y == v->map.height - 1)
		return (put_it(v, pos, 11));
	return (set_image2(v, pos, c));
}
void	display_hp(t_vars *v)
{
	int	i;

	i = -1;
	display_mum_hp(v);
	put_it2(v, new_pos(42 * (v->map.width /2) - 12, 2), 64);
	put_it2(v, new_pos(42 * (v->map.width / 2) - 12, 42 * (v->map.height - 1) - 2), 68);
	put_it2(v, new_pos(2, 42 * (v->map.height / 2) - 12), 66);
	put_it2(v, new_pos(42 * (v->map.width - 1) - 2, 42 * (v->map.height / 2) - 12), 70);

}

void	display_map(t_vars *v)
{
	if (v->map.nb_collectibles == v->player.nb_collectibles)
		display_exits(v);
	display_under_timer(v);
	handle_moove(v, 1);
	v->t = 0;
	display_nearby_floor(v);
	display_under_tears(v);
	display_under_enemies(v);
	tear_travel(v, mlx_put_image_to_window);
	enemies_travel(v, mlx_put_image_to_window);
	put_hp(v);
	put_timer(v);
	put_mooves(v->player.nb_mooves, v);
	mlx_put_image_to_window(v->mlx, v->win, v->map.images[4].img,
		v->p.y + 6, v->p.x + 20);
	mlx_put_image_to_window(v->mlx, v->win, v->map.images[2].img,
		v->p.y + 6, v->p.x);
	display_hp(v);
	death_screen(v);
}

static void	handle_input2(int keycode, t_map *map, t_player *player, int *last_pos)
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

	if (!vars->fire_rate)
		firing(keycode, vars);
	if (!possible_moove(keycode, map->map, player->cp)
		|| (player->mooving > 0 && player->mooving <= 22))
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
