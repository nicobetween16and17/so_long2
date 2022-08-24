/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:33:09 by niespana          #+#    #+#             */
/*   Updated: 2022/08/22 17:33:11 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_front_list_pos(t_list_pos **start, t_list_pos *new)
{
	new->next = *start;
	*start = new;
}

t_list_pos	*new_list_pos(int x, int y)
{
	t_list_pos *saves;

	saves = malloc(sizeof(t_list_pos));
	saves->pos = new_pos(x, y);
	saves->next = NULL;
	return (saves);
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