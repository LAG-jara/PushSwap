/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	use_rarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->val != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b);
		while ((*a)->val != c)
			ft_ra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->val != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b);
		while ((*b)->val != c)
			ft_rb(b);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	use_rrarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->val != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b);
		while ((*a)->val != c)
			ft_rra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->val != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b);
		while ((*b)->val != c)
			ft_rrb(b);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	use_rrarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->val != c)
			ft_rra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a);
		while ((*b)->val != c)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	use_rarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->val != c)
			ft_ra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a);
		while ((*b)->val != c)
			ft_rrb(b);
		ft_pa(a, b);
	}
	return (-1);
}
