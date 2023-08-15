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
static void	choser(t_list *lst,int size)
{
	if(size == 2)
		ft_printf("sa\n");
	if(size == 3)
		alg_3(lst, 0);
	else if(size == 4)
		alg_4(lst);
	//else if(size == 5)
	//	alg_5(lst);
	//else
	//	alg_full(lst);
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

int	ft_check_ordered(int *lst, int size)
{
	int i;

	i = -1;
	while(++i < size)
	{
		if(lst[i] != i)
			return (0);
	}
	return (1);
}

void	ft_listify(int *intlst, int size)
{
	int i;
	t_list	*lst;

	lst = NULL;
	i = -1;
	while(++i < size)
		ft_lstadd_back(&lst, ft_lstnew(intlst[i]));
	i = -1;
	ft_closelst(&lst);
	while(++i < size)
		ft_addprevious(&lst);
	choser(lst, size);
	/*while(lst->nxt != NULL)
	{
		ft_printf("%d",lst->val);
		lst = lst->nxt;
	}
	ft_printf("%d",lst->val);*/
	ft_lstclear(&lst);
	free(intlst);
}

