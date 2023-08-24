/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmax(t_list *a)
{
	int		max;
	t_list	*tmp;

	tmp = a;
	max = a->val;
	a = a->nxt;
	while (a != tmp)
	{
		if (a->val > max)
			max = a->val;
		a = a->nxt;
	}
	while (tmp->val != max)
		tmp = tmp->nxt;
	return (tmp);
}

t_list	*ft_lstmin(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = a->val;
	a = a->nxt;
	while (a != tmp)
	{
		if (a->val < min)
			min = a->val;
		a = a->nxt;
	}
	while (tmp->val != min)
		tmp = tmp->nxt;
	return (tmp);
}

int	ft_lstsize_circ(t_list *a)
{
	int		size;
	t_list	*ctrl;

	size = 0;
	ctrl = a;
	while (++size && a->nxt != ctrl)
		a = a->nxt;
	return (size);
}

void	ft_indexify(int *lst, int *tmp, int size)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size)
	{
		i = -1;
		tmp[j] = 0;
		while (++i < size)
		{
			if (lst[i] < lst[j])
				tmp[j] += 1;
			if (lst[i] == lst[j] && i != j)
				tmp[0] = -1;
		}
	}
	i = -1;
	while (++i < size)
		lst[i] = tmp[i];
	free(tmp);
}

void	ft_lstprint(t_list *a)
{
	t_list	*c;

	if (!a)
		return ;
	ft_printf("\n");
	c = a;
	ft_printf("%d", a->val);
	a = a->nxt;
	while (a != c)
	{
		ft_printf(" %d", a->val);
		a = a->nxt;
	}
	ft_printf("\n");
}
