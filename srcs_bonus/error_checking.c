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

#include "../includes/so_long.h"

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

int	init_game2(t_player *player, int *bool)
{
	if (!bool[0])
		return (mc_error());
	if (!bool[1] && ft_printf("No collectibles error\n"))
		return (-1);
	player->hp = 6;
	player->nb_mooves = 0;
	player->nb_collectibles = 0;
	return (1);
}

int	init_game(t_player *player, t_map *map)
{
	int	i;
	int	j;
	int	bool[2];

	player->cp = new_pos(0, 0);
	bool[0] = 0;
	bool[1] = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P' && player->cp.y != 0)
				map->map[i][j] = '0';
			if (map->map[i][j] == 'P' && !bool[0]++ && !player->cp.y)
				player->cp = new_pos(i, j);
			if (map->map[i][j] == 'C')
				bool[1]++;
		}
	}
	return (init_game2(player, bool));
}

int	nb_avaible_routes(int i, int j, char **map)
{
	int routes;

	routes = 0;
	if (map[i][j + 1] != '1')
		routes++;
	if (map[i][j - 1] != '1')
		routes++;
	if (map[i + 1][j] != '1')
		routes++;
	if (map[i - 1][j] != '1')
		routes++;
	return (routes);
}

t_position	next_avaible_routes(int i, int j, char **map)
{
	if (map[i][j + 1] != '1')
		return (new_pos(i, j + 1));
	if (map[i][j - 1] != '1')
		return (new_pos(i, j - 1));
	if (map[i + 1][j] != '1')
		return (new_pos(i + 1, j));
	return (new_pos(i - 1, j));
}

t_list_pos	*new_list_pos(int x, int y)
{
	t_list_pos *saves;

	saves = malloc(sizeof(t_list_pos));
	saves->pos = new_pos(x, y);
	saves->next = NULL;
	return (saves);
}

void	display(char **map, int i, int j, t_position current)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				ft_printf("\e[0;31m");
			if (map[i][j] == 'C')
				ft_printf("\e[0;33m");
			if (map[i][j] == 'P')
				ft_printf("\e[0;34m");
			if (map[i][j] == 'E')
				ft_printf("\e[0;35m");
			if (i == current.x && j == current.y)
				ft_printf("\e[0;32m");
			ft_printf("%c", map[i][j]);
			ft_printf("\e[0m");
		}

		ft_printf("\n");
	}
}

void	add_front_list_pos(t_list_pos **start, t_list_pos *new)
{
	new->next = *start;
	*start = new;
}

int	clear_path(t_position object, t_position player, char **map)
{
	t_list_pos	*save;
	t_position	current;

	current = new_pos(object.x, object.y);
	save = new_list_pos(object.x, object.y);
	while (current.x != player.x || current.y != player.y)
	{
		display(map, -1, -1, current);
		while (save && nb_avaible_routes(current.x, current.y, map) == 0)
		{
			map[current.x][current.y] = '1';
			current.x = save->pos.x;
			current.y = save->pos.y;
			save = save->next;
		}
		if (!save)
			return (0);
		if (nb_avaible_routes(current.x, current.y, map) > 1)
			add_front_list_pos(&save, new_list_pos(current.x, current.y));
		map[current.x][current.y] = '1';
		current = next_avaible_routes(current.x, current.y, map);
	}
	return (1);
}

char	**duplicate_map(char **map)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	while(map[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while(map[++i])
	{
		j = -1;
		res[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!(res[i]))
			return (NULL);
		while (map[i][++j])
			res[i][j] = map[i][j];
		res[i][j] = 0;
	}
	res[i] = 0;
	return (res);
}

void	cpy_map(char **map, char **save)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			map[i][j] = save[i][j];
	}
}

int avaible_path(char **map, int i, int j, t_position player)
{
	int		res;
	char	**save;

	save = duplicate_map(map);
	res = 1;
	display(map, -1, -1, new_pos(0, 0));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				if (!clear_path(new_pos(i, j), player, map))
				{
					res = 0;
					break ;
				}
				cpy_map(map, save);
			}
		}
	}
	free_map_array(save);
	return (res);
}