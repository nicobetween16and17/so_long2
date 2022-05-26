/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:16:52 by niespana          #+#    #+#             */
/*   Updated: 2022/05/14 14:16:53 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_ui_timer(t_vars *v)
{
	v->timer.s++;
	if (v->timer.s == 60)
	{
		v->timer.s = 0;
		v->timer.m++;
		if (v->timer.m == 60)
		{
			v->timer.m = 0;
			v->timer.h++;
		}
	}
}

void	tear_travel(t_vars *v, int (*f)(void *, void *, void *, int, int))
{
	t_tear	*t;
	t_list	*start;

	if (!(v->tears))
		return ;
	start = v->tears;
	ft_lstiter(v->tears, duration_plus_one);
	ft_lstiter(v->tears, position_shift);
	while (v->tears)
	{
		t = (t_tear *)v->tears->content;
		f(v->mlx, v->win, v->map.images[30].img, t->cp.y, t->cp.x);
		v->tears = v->tears->next;
	}
	v->tears = start;
	v->tears = clean_tears(start, v);
}

void	set_head(t_sens d, t_vars *v)
{
	if (d == UP)
		v->map.images[7].img = v->map.images[40].img;
	if (d == UP)
		v->map.images[8].img = v->map.images[40].img;
	if (d == LEFT)
		v->map.images[7].img = v->map.images[41].img;
	if (d == LEFT)
		v->map.images[8].img = v->map.images[42].img;
	if (d == DOWN)
		v->map.images[7].img = v->map.images[49].img;
	if (d == DOWN)
		v->map.images[8].img = v->map.images[50].img;
	if (d == RIGHT)
		v->map.images[7].img = v->map.images[39].img;
	if (d == RIGHT)
		v->map.images[8].img = v->map.images[43].img;
	if (d == UP)
		v->map.images[67].img = v->map.images[40].img;
	if (d == LEFT)
		v->map.images[67].img = v->map.images[41].img;
	if (d == DOWN)
		v->map.images[67].img = v->map.images[49].img;
	if (d == RIGHT)
		v->map.images[67].img = v->map.images[39].img;
	v->event = v->time + 5;
}

void	firing(int key, t_vars *v)
{
	t_tear		*new;

	new = malloc(sizeof(t_tear));
	if (!new)
		return ;
	if (key == 126)
		new->s = UP;
	else if (key == 123)
		new->s = LEFT;
	else if (key == 125)
		new->s = DOWN;
	else if (key == 124)
		new->s = RIGHT;
	else
		return ;
	set_head(new->s, v);
	new->duration = 0;
	system("afplay sound/splatter0.wav &");
	new->cp = new_pos((v->p.x) + 21, (v->p.y) + 21);
	ft_lstadd_back(&(v->tears), ft_lstnew((void *)new));
	v->map.images[7].img = v->map.images[8].img;
}

void	set_direction(t_vars *v, int keycode)
{
	if (keycode == 13)
		v->direction = UP;
	if (keycode == 0)
		v->direction = LEFT;
	if (keycode == 2)
		v->direction = RIGHT;
	if (keycode == 1)
		v->direction = DOWN;
}
