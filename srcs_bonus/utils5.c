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

void	display_under_tears(t_vars *v)
{
	t_tear	*t;
	t_list	*start;

	if (!(v->tears))
		return ;
	start = v->tears;
	while (v->tears)
	{
		t = (t_tear *)v->tears->content;
		display_near_tears(v, t->cp);
		v->tears = v->tears->next;
	}
	v->tears = start;
}
