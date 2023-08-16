/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_lst_id(t_list *lst, int id)
{
	while(id)
	{
		lst = lst->nxt;
		id--;
	}
	return(lst->val);
}

void	alg_3(t_list *lst, int fun)
{

	if (ft_read_lst_id(lst, fun) == 0)
	{
		if (ft_read_lst_id(lst, 1 + fun) == 2)
			ft_printf("ss\nrr\n");
	}
	else if (ft_read_lst_id(lst, fun) == 1)
	{
		if (ft_read_lst_id(lst, 1 + fun) == 0)
			ft_printf("ss\n");
		else
			ft_printf("rrr\n");
	}
	else if (ft_read_lst_id(lst, fun) == 2)
	{
		// ft_printf("%d",lst[2].val);
		if (ft_read_lst_id(lst, 1 + fun) == 0)
			ft_printf("rr\n");
		else
			ft_printf("rr\nss\n");

	}
}

void	alg_3for4(t_list *lst, int fun)
{
	if (lst->val == 0)
	{
		if (ft_read_lst_id(lst, 1 + fun) == 2)
			ft_printf("ss\nrr\n");
	}
	else if (lst->val == 1)
	{
		if (ft_read_lst_id(lst, 1 + fun) == 0)
			ft_printf("ss\n");
		else
			ft_printf("rrr\n");
	}
	else
	{
		if (ft_read_lst_id(lst, 1 + fun) == 0)
			ft_printf("rr\n");
		else
			ft_printf("rr\nss\n");

	}
}

void	alg_4(t_list *lst)
{
	if (ft_read_lst_id(lst, 3) == 3)
	{
		ft_printf("rrr\npb\n");
		alg_3(lst, 0);
		ft_printf("pa\nrr\n");
	}
	else if (lst->val == 3)
	{
		ft_printf("pb\n");
		alg_3(lst, 1);
		ft_printf("pa\nrr\n");
	}
	else if (ft_read_lst_id(lst, 1) == 3)
	{
		ft_printf("rr\npb\nrrr\n");
		alg_3for4(lst, 0);
		ft_printf("pa\nrr\n");
	}
	else
	{
		ft_printf("rrr\nrrr\npb\nrr\n");
		alg_3for4(lst, 1);
		ft_printf("pa\nrr\n");
	}
}

t_list	*alg_5(t_list *A)
{
	t_list *B;
	t_list *tmp;
	t_list *ctrl;


	B = NULL;
	while (A->val != 2)
	{
		ft_printf("%d",A->val);
		if (A != A->nxt)
			tmp = A->nxt;
		else
			tmp = NULL;
		B = push(A, B);
		A = tmp;
	}
	while (B->nxt != B)
	{
		ft_printf("%d",B->val);
		tmp = B->nxt;
		A = push(B, A);
		B = tmp;
	}
	A = push(B, A);
	ft_printf("STACK B: ");
	ctrl = B;
	if(B)
	{
		while(B->nxt != ctrl )
		{
			ft_printf("%d",B->val);
			B = B->nxt;
			usleep(1000000);
		}
		ft_printf("%d\n",B->val);
	}
	//lst = swap(lst);
	return (A);
}
//void	alg_full(t_list *lst);