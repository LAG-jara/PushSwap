/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_list *a, int nbr)
{
	int		i;

	i = 0;
	while (a->val != nbr)
	{
		i++;
		a = a->nxt;
	}
	return (i);
}

int	ft_find_place_b(t_list *stack_b, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push > stack_b->val && nbr_push < stack_b->pre->val)
		i = 0;
	else if (nbr_push > (ft_lstmax(stack_b))->val \
		|| nbr_push < (ft_lstmin(stack_b))->val)
		i = ft_find_index(stack_b, (ft_lstmin(stack_b))->val);
	else
	{
		tmp = stack_b->nxt;
		while (stack_b->val < nbr_push || tmp->val > nbr_push)
		{
			stack_b = stack_b->nxt;
			tmp = stack_b->nxt;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_list *stack_a, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push < stack_a->val && nbr_push > stack_a->pre->val)
		i = 0;
	else if (nbr_push > (ft_lstmax(stack_a))->val \
		|| nbr_push < (ft_lstmin(stack_a))->val)
		i = ft_find_index(stack_a, (ft_lstmin(stack_a))->val);
	else
	{
		tmp = stack_a->nxt;
		while (stack_a->val > nbr_push || tmp->val < nbr_push)
		{
			stack_a = stack_a->nxt;
			tmp = stack_a->nxt;
			i++;
		}
	}
	return (i);
}
