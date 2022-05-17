/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:56:02 by niespana          #+#    #+#             */
/*   Updated: 2022/04/05 14:56:03 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		mem = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = mem;
	}
}
