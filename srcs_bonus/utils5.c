/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:17:35 by niespana          #+#    #+#             */
/*   Updated: 2022/06/05 11:17:37 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_exits(t_vars *v)
{
	t_position	p;

	p.y = -1;
	while (v->map.map[++p.y])
	{
		p.x = -1;
		while (v->map.map[p.y][++p.x])
		{
			if (v->map.map[p.y][p.x] == 'E')
				set_image(v, p, v->map.map[p.y][p.x]);
		}
	}
}
