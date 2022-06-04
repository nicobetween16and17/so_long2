/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:34:58 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 11:35:00 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	end_game(t_map map)
{
	free_map_array(map.map);
	free(map.exits);
}

int	collision_effect(t_position p, t_vars *v, int i)
{
	while (v->shits[++i].p.x != -1)
	{
		if (v->shits[i].p.x == p.x && v->shits[i].p.y == p.y)
		{
			system("afplay sound/tear_block.wav &");
			v->shits[i].state -= 1;
		}
	}
	return (1);
}

int	collision_pos(t_position obj, t_position larme, t_vars *v)
{
	if (obj.x + 42 > larme.x && obj.x < larme.x
		&& obj.y + 42 > larme.y && obj.y < larme.y)
		return (collision_effect(new_pos(obj.y / 42, obj.x / 42), v, -1));
	if (larme.x < 21 || larme.y < 31)
		return (1);
	return (0);
}

int	collision(t_position current, t_vars *v, int i, int j)
{
	char	**map;

	map = v->map.map;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '1'
				&& collision_pos(new_pos(i * 42, j * 42), current, v))
				return (1);
		}
	}
	return (0);
}
