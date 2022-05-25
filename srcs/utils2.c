/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:01:51 by niespana          #+#    #+#             */
/*   Updated: 2022/05/25 11:01:53 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_position	new_pos(int x, int y)
{
	t_position	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	moove_toward(t_vars *v, t_fly *fly)
{
	if (v->p.x > fly->h.y)
		fly->h.y += 4;
	else if (v->p.y > fly->h.x)
		fly->h.x += 4;
	else if (v->p.x < fly->h.y)
		fly->h.y -= 4;
	else if (v->p.y < fly->h.x)
		fly->h.x -= 4;
}

void	enemies_travel(t_vars *v, int (*f)(void *, void *, void *, int, int))
{
	int	i;
	int	j;

	j = v->time;
	srand(v->time % 27);
	i = -1;
	while (v->flies[++i].hp != -1)
	{
		if (j % 4 == 0)
			v->flies[i].h.x += rand() % 4;
		if (j % 4 == 1)
			v->flies[i].h.y -= rand() % 4;
		if (j % 4 == 2)
			v->flies[i].h.x -= rand() % 4;
		if (j % 4 == 3)
			v->flies[i].h.y += rand() % 4;
		if (!(v->time % 2))
			moove_toward(v, &v->flies[i]);
		f(v->mlx, v->win, v->sprites[5]->content,
			v->flies[i].h.x, v->flies[i].h.y);
	}
}
