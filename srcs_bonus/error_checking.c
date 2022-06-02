/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:18:03 by niespana          #+#    #+#             */
/*   Updated: 2022/05/03 16:18:04 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_line(char *s)
{
	while (*s)
	{
		if (*s != '1')
			return (1);
		s++;
	}
	return (0);
}

int	check_error(t_map *map)
{
	int	i;

	map->width = ft_strlen2(map->map[0]);
	i = -1;
	while (map->map[++i])
	{
		if (ft_strlen2(map->map[i]) != map->width)
		{
			free_map_array(map->map);
			return (map_error());
		}
		if ((i == 0 || map->map[i + 1] == NULL) && check_line(map->map[i]))
			return (wall_error());
		if ((i > 0 && map->map[i + 1] != NULL)
			&& (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1'))
			return (wall_error());
	}
	map->height = i;
	i = 0;
	while (map->exits[i].x != -1)
		i++;
	if (!i)
		return (no_exit_error());
	return (1);
}

int	init_game2(t_player *player)
{
	player->nb_mooves = 0;
	player->nb_collectibles = 0;
	player->hp = 3;
	return (1);
}

int	init_game(t_player *player, t_map map)
{
	int	i;
	int	j;
	int	bool;

	bool = 1;
	i = -1;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j])
		{
			if (map.map[i][j] == 'P' && bool--)
			{
				player->cp.x = i;
				player->cp.y = j;
			}
		}
	}
	if (bool != 0)
		return (mc_error());
	return (init_game2(player));
}
