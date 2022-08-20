/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:08:04 by niespana          #+#    #+#             */
/*   Updated: 2022/05/16 13:08:05 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	duration_plus_one(void *arg)
{
	t_tear	*current;

	current = (t_tear *)arg;
	current->duration++;
	if (current->duration > 15)
		current->visibility = 0;
}

void	position_shift(void *arg)
{
	t_tear	*current;

	current = (t_tear *)arg;
	if (current->s == UP)
		current->cp.x -= 15;
	if (current->s == DOWN)
		current->cp.x += 15;
	if (current->s == LEFT)
		current->cp.y -= 15;
	if (current->s == RIGHT)
		current->cp.y += 15;
}

void	init_sprites(t_vars *v, int start, int end, int lst)
{
	int		i;
	t_list	*new;

	i = start -1;
	new = ft_lstnew(v->map.images[++i].img);
	while (++i <= end)
		ft_lstadd_back(&new, ft_lstnew(v->map.images[i].img));
	ft_lstadd_back(&new, new);
	v->sprites[lst] = new;
}

void	init_all_sprites(t_vars *v)
{
	init_sprites(v, 4, 7, 0);
	init_sprites(v, 4, 7, 1);
	init_sprites(v, 28, 30, 2);
	init_sprites(v, 24, 26, 3);
	init_sprites(v, 2, 3, 4);
	init_sprites(v, 54, 58, 5);
	v->sprites[6] = NULL;
}

void	display_all(t_vars *v)
{
	t_position	pos;

	pos.y = -1;
	while (v->map.map[++pos.y])
	{
		pos.x = -1;
		while (v->map.map[pos.y][++pos.x])
			set_image(v, pos, v->map.map[pos.y][pos.x]);
	}
}
