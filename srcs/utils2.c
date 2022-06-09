/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:35:59 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 13:36:00 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	nb_exit(char **map)
{
	int	i;
	int	j;
	int	nb_exits;

	nb_exits = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				nb_exits++;
			j++;
		}
		i++;
	}
	return (nb_exits + 1);
}

t_position	*exits(char **map)
{
	t_position	*exit_list;
	int			i[3];

	i[2] = 0;
	exit_list = malloc(nb_exit(map) * sizeof(t_position));
	if (!exit_list)
		return (NULL);
	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			if (map[i[0]][i[1]] == 'E')
			{
				exit_list[i[2]].x = i[0];
				exit_list[i[2]++].y = i[1];
			}
			i[1]++;
		}
		i[0]++;
	}
	exit_list[i[2]].x = -1;
	return (exit_list);
}

int	is_exit(t_position player, t_position *list)
{
	int	i;

	i = 0;
	while (list[i].x != -1)
	{
		if (list[i].x == player.x && list[i].y == player.y)
			return (1);
		i++;
	}
	return (0);
}

t_position	new_pos(int x, int y)
{
	t_position	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
