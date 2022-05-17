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

t_list	*clean_tears(t_list *old)
{
	t_list	*new;
	t_tear	*current;

	new = NULL;
	while (old)
	{
		current = (t_tear *)(old->content);
		if (current->duration <= 15)
			ft_lstadd_back(&new, ft_lstnew(old->content));
		old = old->next;
	}
	return (new);
}

void *init_sprites(char *path)
{
	int		fd;
	char	*joined1;
	char	*joined2;
	char	to_join[2];

	to_join[1] = 0;
	to_join[0] = '1';
	joined1 = ft_strjoin(path, to_join);
	joined2 = ft_strjoin(joined1, ".xpm");
	fd = open(joined2, O_RDONLY);
	free(joined1);
	free(joined2);
}