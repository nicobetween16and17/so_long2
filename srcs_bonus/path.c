/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:32:57 by niespana          #+#    #+#             */
/*   Updated: 2022/08/22 17:32:59 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nb_avaible_routes(int i, int j, char **map)
{
	int	routes;

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
	while (map[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (map[++i])
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

int	avaible_path(char **map, int i, int j, t_position player)
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
