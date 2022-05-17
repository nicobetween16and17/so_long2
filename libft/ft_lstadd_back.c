/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:55:32 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 14:55:33 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*(lst));
		tmp->next = new;
	}
}
/*
#include <stdio.h>
int main()
{
	t_list *l;
	t_list l1;
	t_list l2;
	t_list l3;
	t_list l4;
	t_list l5;
	t_list l6;
	t_list l7;
	t_list l8;

	l->content = (void *)1;
	l->next= &l1;
	l1.content = (void *)2;
	l1.next= &l2;
	l2.content = (void *)3;
	l2.next= &l3;
	l3.content = (void *)4;
	l3.next= &l4;
	l4.content = (void *)5;
	l4.next= &l5;
	l5.content = (void *)6;
	l5.next= &l6;
	l6.content = (void *)7;
	l6.next= &l7;
	l7.content = (void *)8;
	l7.next = 0;
	l8.content = (void *)9;
	l8.next = 0;
	ft_lstadd_back(&l, &l8);
	void *test = ft_lstlast(l)->content;
	printf("%d", test);
}*/
