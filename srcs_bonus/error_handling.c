/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:47:19 by niespana          #+#    #+#             */
/*   Updated: 2022/08/24 11:47:20 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_commands(t_vars *v)
{
	ft_strlcpy(v->baby_dead_s_effect, "afplay sound/isaac_dies"
		"_new.wav ", 80);
	ft_strlcpy(v->baby_hurt_s_effect, "afplay sound/baby_hurt_1.wav &", 80);
	ft_strlcpy(v->background_music_kill, "ps -a|grep afplay|grep -v "
		"'grep'|awk '{print $1}'|xargs kill -15", 80);
	ft_strlcpy(v->background_music_start, "afplay sound/the_caves."
		"wav -t 100 &", 80);
	ft_strlcpy(v->penny_pickup_s_effect, "afplay sound/penny_pickup"
		"_1.wav &", 80);
	ft_strlcpy(v->poop_poping_s_effect, "afplay sound/plop.wav &", 80);
	ft_strlcpy(v->summon_s_effect, "afplay sound/summonsound.wav &", 80);
	ft_strlcpy(v->traps_open_s_effect, "afplay sound/golden_key.wav &", 80);
	ft_strlcpy(v->tears_sound_effect, "afplay sound/splatter0.wav &", 80);
	ft_strlcpy(v->tears_collision_s_effect, "afplay sound/tear_b"
		"lock.wav &", 80);
}

int	issues(int argc, t_vars *v, char **argv)
{
	put_commands(v);
	if (argc != 2)
		return (argument_error());
	v->map.map = get_map(argv[1]);
	if (!v->map.map && ft_printf("Error: empty map\n"))
		return (1);
	v->map.nb_collectibles = nb_collectible(v->map);
	v->map.exits = exits(v->map.map);
	if (check_error(&(v->map)) == -1)
		return (1);
	v->map.data_size = 42;
	set_vars(v);
	if (init_game(&v->player, &(v->map)) == -1)
		return (1);
	if (!avaible_path(v->map.map, -1, -1, v->player.cp)
		&& ft_printf("Error: no paths avaible\n"))
		return (1);
	return (0);
}
