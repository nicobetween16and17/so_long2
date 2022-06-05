/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:32:41 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 13:32:41 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**free_map_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (NULL);
}

void	end_game(t_map map)
{
	free_map_array(map.map);
	free(map.exits);
}

int	possible_moove(int key, char **map, t_position pos)
{
	if (key == 13)
		return (map[pos.x - 1][pos.y] != '1');
	if (key == 0)
		return (map[pos.x][pos.y - 1] != '1');
	if (key == 2)
		return (map[pos.x][pos.y + 1] != '1');
	if (key == 1)
		return (map[pos.x + 1][pos.y] != '1');
	return (0);
}

int	put_it(t_vars *vars, t_position pos, int img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.images[img].img,
		pos.x * vars->map.data_size, pos.y * vars->map.data_size);
	return (1);
}
