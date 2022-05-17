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
	ft_printf(" %dh/%dm/%ds\n", v->timer.h, v->timer.m, v->timer.s);
}

void	tear_travel(t_vars *v, int (*f)(void *, void *, void *, int, int))
{
	t_tear	*t;
	t_list	*start;
	int cpt;

	cpt = 0;
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
	v->tears = clean_tears(start);
}

void	firing(int key, t_vars *v)
{
	t_tear		*new;

	new = malloc(sizeof(t_tear));
	if (!new)
		return ;
	if (key == 126)//up
		new->s = UP;
	else if (key == 123)//left
		new->s = LEFT;
	else if (key == 125)//down
		new->s = DOWN;
	else if (key == 124)//right
		new->s = RIGHT;
	else
		return ;
	new->duration = 0;
	system("afplay sound/splatter0.wav &");
	new->cp = new_pos((v->player.cp.x * 42) + 21, (v->player.cp.y * 42) + 21);
	ft_lstadd_back(&(v->tears), ft_lstnew((void *)new));
}


