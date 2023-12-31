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

void	alg_3(t_list **a)
{
	t_list	*min;
	t_list	*max;

	max = ft_lstmax(*a);
	min = ft_lstmin(*a);
	if (*a == min && (*a)->nxt == max)
		ft_sa(a);
	if (*a == max && (*a)->nxt == min)
		ft_ra(a);
	if (*a == max)
		ft_sa(a);
	if ((*a)->nxt == max)
		ft_rra(a);
	if (!ft_check_sorted(*a))
		ft_sa(a);
}

void	ft_empty_a_but_3(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (ft_lstsize_circ(*stack_a) > 3 && !ft_check_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->val))
				i = use_rarb(stack_a, stack_b, tmp->val, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->val))
				i = use_rrarrb(stack_a, stack_b, tmp->val, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->val))
				i = use_rarrb(stack_a, stack_b, tmp->val, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->val))
				i = use_rrarb(stack_a, stack_b, tmp->val, 'a');
			else
				tmp = tmp->nxt;
		}
	}
}

t_list	*ft_sort_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize_circ(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_lstsize_circ(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_lstsize_circ(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_empty_a_but_3(stack_a, &stack_b);
	if (!ft_check_sorted(*stack_a))
		alg_3(stack_a);
	return (stack_b);
}

t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->val))
				i = use_rarb(stack_a, stack_b, tmp->val, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->val))
				i = use_rarrb(stack_a, stack_b, tmp->val, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->val))
				i = use_rrarrb(stack_a, stack_b, tmp->val, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->val))
				i = use_rrarb(stack_a, stack_b, tmp->val, 'b');
			else
				tmp = tmp->nxt;
		}
	}
	return (stack_a);
}

void	alg_big(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		if ((*stack_a)->val < ft_lstsize_circ(*stack_a) - (*stack_a)->val)
		{
			while (*stack_a != ft_lstmin(*stack_a))
				ft_rra(stack_a);
		}
		else
		{
			while (*stack_a != ft_lstmin(*stack_a))
				ft_ra(stack_a);
		}
	}
}
