/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:58:49 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 12:58:50 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	check_line(char *s)
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
	if ((!i && n_e_error()) || (i > 1 && ft_printf("Error: 2 many exits\n")))
		return (-1);
	return (1);
}

static int	init_game2(t_player *player, int *bool)
{
	if (!bool[0])
		return (mc_error());
	if (!bool[1] && ft_printf("No collectibles error\n"))
		return (-1);
	player->nb_mooves = 0;
	player->nb_collectibles = 0;
	return (1);
}

int	init_game(t_player *player, t_map *map)
{
	int	i;
	int	j;
	int	bool[2];

	bool[0] = 0;
	bool[1] = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P' && player->cp.y)
				map->map[i][j] = '0';
			if (map->map[i][j] == 'P' && !bool[0]++ && !player->cp.y)
				player->cp = new_pos(i, j);
			if (map->map[i][j] == 'C')
				bool[1]++;
		}
	}
	return (init_game2(player, bool));
}
