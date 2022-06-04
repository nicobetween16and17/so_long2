/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:09:03 by niespana          #+#    #+#             */
/*   Updated: 2022/05/25 07:09:05 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_hp(t_vars *v)
{
	t_position	pos;

	pos.y = -1;
	pos.x = 1;
	while (++pos.y < v->player.hp / 2)
		mlx_put_image_to_window(v->mlx, v->win,
			v->map.images[19].img, 15 * pos.x++ + 25, 42);
	pos.y = -1;
	while (++pos.y < v->player.hp % 2)
		mlx_put_image_to_window(v->mlx, v->win,
			v->map.images[20].img, 15 * pos.x++ + 25, 42);
	pos.y = -1;
	while (++pos.y < 3 - ((v->player.hp % 2) + (v->player.hp / 2)))
		mlx_put_image_to_window(v->mlx, v->win,
			v->map.images[21].img, 15 * pos.x++ + 25, 42);
}

int	put_shit(t_vars *v, t_position p, int i)
{
	while (v->shits[++i].p.x != -1)
	{
		if (v->shits[i].p.x == p.x && v->shits[i].p.y == p.y)
		{
			if (v->shits[i].state == 5)
				put_it(v, p, 0);
			else if (v->shits[i].state == 4)
				put_it(v, p, 37);
			else if (v->shits[i].state == 3)
				put_it(v, p, 38);
			else if (v->shits[i].state == 2)
				put_it(v, p, 39);
			else if (v->shits[i].state <= 1)
			{
				system("afplay sound/plop.wav &");
				v->map.map[p.y][p.x] = 'M';
			}
		}
		if (v->map.map[p.y][p.x] == 'M')
			return (0);
	}
	return (1);
}

int	put_it2(t_vars *vars, t_position pos, int img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.images[img].img,
		pos.x, pos.y);
	return (1);
}

void	put_timer(t_vars *v)
{
	put_it2(v, new_pos(192, 42), 53);
	put_it2(v, new_pos(202, 42), 43 + v->timer.s % 10);
	put_it2(v, new_pos(192, 42), 43 + v->timer.s / 10);
	put_it2(v, new_pos(172, 42), 43 + v->timer.m % 10);
	put_it2(v, new_pos(162, 42), 43 + v->timer.m / 10);
	put_it2(v, new_pos(152, 42), 53);
	put_it2(v, new_pos(142, 42), 43 + v->timer.h % 10);
	put_it2(v, new_pos(132, 42), 43 + v->timer.h / 10);
}

void	put_mooves(int nb, t_vars *v)
{
	long int	n;

	n = nb;
	if (n >= 10)
	{
		put_mooves(n / 10, v);
		put_mooves(n % 10, v);
	}
	else
	{
		put_it2(v, new_pos(42 + v->t, 62), n + 43);
		v->t += 10;
	}
}
