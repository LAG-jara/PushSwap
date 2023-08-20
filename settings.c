/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//		FULL OF FUNC
void	choser(t_list **a)
{
	int		size;

	size = ft_lstsize_circ(*a);
	if(size == 2)
		ft_sa(a);
	else if(size == 3)
		alg_3(a);
	else
	 	alg_big(a);
}

static void ft_closelst(t_list **lst)
{
	t_list	*first;

	first = (*lst);
	while ((*lst)->nxt)
		(*lst) = (*lst)->nxt;
	(*lst)->nxt = first;
}

static void ft_addprevious(t_list **lst)
{
	t_list	*prev;

	while(NULL == (*lst)->nxt->pre)
	{
		prev = (*lst);
		(*lst) = (*lst)->nxt;
		(*lst)->pre = prev;
	}
}



void	ft_listify(int *intlst, int size)
{
	int i;
	t_list	*lst;
	t_list	*ctrl;

	lst = NULL;
	i = -1;
	while(++i < size)
		ft_lstadd_back(&lst, ft_lstnew(intlst[i]));
	ft_closelst(&lst);
	ft_addprevious(&lst);
	choser(&lst);
	ctrl = lst;
	lst->pre->nxt = NULL;
	ft_lstclear(&lst);
	free(intlst);
}

