/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:27:37 by niespana          #+#    #+#             */
/*   Updated: 2022/05/27 08:27:38 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_sprites(t_vars *v)
{
	int		i;
	t_list	**first;

	i = -1;
	while (v->sprites[++i])
	{
		first = &v->sprites[i];
		while (&v->sprites[i]->next != first)
		{
			free(v->sprites[i]->content);
			v->sprites[i] = v->sprites[i]->next;
		}
		v->sprites[i]->next = NULL;
		ft_lstclear(first, free);
	}
}

int	damage(t_vars *v, int i, t_sens s)
{
	v->flies[i].hp--;
	if (v->flies[i].hp)
	{
		if (s == UP)
			v->flies[i].h.y -= 20;
		if (s == DOWN)
			v->flies[i].h.y += 20;
		if (s == RIGHT)
			v->flies[i].h.x += 20;
		if (s == LEFT)
			v->flies[i].h.x -= 20;
	}
	return (1);
}

int	damaging(t_vars *v, t_tear *crt)
{
	int	i;

	i = -1;
	while (v->flies[++i].h.x != -1)
	{
		if (v->flies[i].h.y - 20 < crt->cp.x && v->flies[i].h.y + 20 > crt->cp.x
			&& v->flies[i].h.x - 20 < crt->cp.y
			&& v->flies[i].h.x + 20 > crt->cp.y && v->flies[i].hp > 0)
		{
			crt->duration = 16;
			crt->cp = new_pos(-5, -5);
			damage(v, i, crt->s);
		}
	}
	return (0);
}

void	take_damage(t_vars *v, int i)
{
	while (v->flies[++i].h.x > -1)
	{
		if (v->flies[i].h.y - 20 < v->p.x && v->flies[i].h.y + 20 > v->p.x
			&& v->flies[i].h.x - 20 < v->p.y && v->flies[i].h.x + 20 > v->p.y
			&& v->flies[i].hp > 0 && !v->immune)
		{
			system("afplay sound/baby_hurt_1.wav &");
			v->player.hp--;
			if (v->player.hp - 1 < 0)
			{
				v->dead = 1;
				v->event = v->time + 5;
			}
			v->immune = v->time + 40;
		}
	}
}

void	death_screen(t_vars *v)
{
	if (v->dead)
	{
		put_it(v, new_pos(0, 0), 60);
		mlx_put_image_to_window(v->mlx, v->win, v->map.images[61].img,
			v->map.width * v->map.data_size / 2 - 150,
			v->map.height * v->map.data_size / 2 - 50);
		mlx_put_image_to_window(v->mlx, v->win, v->map.images[62].img,
			v->map.width * v->map.data_size / 2 - 22,
			v->map.height * v->map.data_size / 2 + 22);
		v->player.hp--;
	}
}
