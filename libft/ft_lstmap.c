/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:56:27 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 14:56:27 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	void	*new_content;

	start = NULL;
	while (lst && f && del)
	{
		new_content = f(lst->content);
		ft_lstadd_back(&start, ft_lstnew(new_content));
		if (!ft_lstlast(start))
		{
			ft_lstclear(&start, del);
			return (0);
		}
		lst = lst->next;
	}
	return (start);
}
/*
void * addOne(void * p) {
 void * r = malloc(sizeof(int));
 *(int*)r = *(int*)p + 1; return (r);
 * }
#include <stdio.h>

int main ()
{
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list * m = ft_lstmap(l, addOne, free);
}*/
