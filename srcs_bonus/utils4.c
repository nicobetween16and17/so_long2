/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:20:27 by niespana          #+#    #+#             */
/*   Updated: 2022/06/04 19:20:28 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_walls(t_vars *v)
{
	t_position	p;

	p.y = -1;
	while (v->map.map[++p.y])
	{
		p.x = -1;
		while (v->map.map[p.y][++p.x])
		{
			if (v->map.map[p.y][p.x] == '1' && (p.y == 0
				|| p.x == 0 || p.y == v->map.height || p.x == v->map.width))
				set_image(v, p, v->map.map[p.y][p.x]);
		}
	}
}

void	display_shits(t_vars *v)
{
	t_position	p;

	p.y = -1;
	while (v->map.map[++p.y])
	{
		p.x = -1;
		while (v->map.map[p.y][++p.x])
		{
			if ((v->map.map[p.y][p.x] == '1' && !(p.y == 0 || p.x == 0
					|| p.y == v->map.height - 1 || p.x == v->map.width - 1))
				|| v->map.map[p.y][p.x] == 'M')
				set_image(v, p, v->map.map[p.y][p.x]);
		}
	}
}

void	display_nearby_floor(t_vars *v)
{
	t_position	p;

	p.y = -1;
	while (v->map.map[++p.y])
	{
		p.x = -1;
		while (v->map.map[p.y][++p.x])
		{
			if (p.y <= v->player.cp.x + 2 && p.y >= v->player.cp.x - 2
				&& p.x <= v->player.cp.y + 2 && p.x >= v->player.cp.y - 2)
				set_image(v, p, v->map.map[p.y][p.x]);
		}
	}
}

int	display_near_tears(t_vars *v, t_position tear)
{
	t_position	p;

	p.y = -1;
	while (v->map.map[++p.y])
	{
		p.x = -1;
		while (v->map.map[p.y][++p.x])
		{
			if ((p.x * 42 <= tear.y + 62 && p.x * 42 >= tear.y - 62)
				&& (p.y * 42 <= tear.x + 62 && p.y * 42 >= tear.x - 62))
				set_image(v, p, v->map.map[p.y][p.x]);
		}
	}
	return (1);
}

void	display_under_timer(t_vars *v)
{
	t_position	p;

	p.y = -1;
	while (++p.y < 2)
	{
		p.x = -1;
		while (++p.x <= 4)
			set_image(v, p, v->map.map[p.y][p.x]);
	}
}
