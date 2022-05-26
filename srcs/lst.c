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

#include "so_long.h"

void	duration_plus_one(void *arg)
{
	t_tear	*current;

	current = (t_tear *)arg;
	current->duration++;
	arg = (void *)current;
}

void	position_shift(void *arg)
{
	t_tear	*current;

	current = (t_tear *)arg;
	if (current->s == UP)
		current->cp.x -= 10;
	if (current->s == DOWN)
		current->cp.x += 10;
	if (current->s == LEFT)
		current->cp.y -= 10;
	if (current->s == RIGHT)
		current->cp.y += 10;
	arg = (void *)(current);
}

t_list	*clean_tears(t_list *old, t_vars *v)
{
	t_list	*new;
	t_tear	*current;

	new = NULL;
	while (old)
	{
		current = (t_tear *)(old->content);
		if (current->duration <= 15 && !collision(current->cp, v, -1, -1))
			ft_lstadd_back(&new, ft_lstnew(old->content));
		old = old->next;
	}
	return (new);
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
	init_sprites(v, 9, 12, 0);
	init_sprites(v, 9, 12, 1);
	init_sprites(v, 35, 38, 2);
	init_sprites(v, 31, 34, 3);
	init_sprites(v, 7, 8, 4);
	init_sprites(v, 62, 66, 5);
}
