/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_addprevious(t_list **lst)
{
	t_list	*prev;

	while (NULL == (*lst)->nxt->pre)
	{
		prev = (*lst);
		(*lst) = (*lst)->nxt;
		(*lst)->pre = prev;
	}
}

void	ft_listify(int *intlst, int size)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	i = -1;
	while (++i < size)
		ft_lstadd_back(&lst, ft_lstnew(intlst[i]));
	(ft_lstlast(lst))->nxt = lst;
	ft_addprevious(&lst);
	if (size == 3)
		alg_3(&lst);
	else
		alg_big(&lst);
	free(intlst);
	lst->pre->nxt = NULL;
	ft_lstclear(&lst);
}
