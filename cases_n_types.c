/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_and_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_type_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->val);
	while (42)
	{
		if (i > ft_case_rarb_a(a, b, tmp->val))
			i = ft_case_rarb_a(a, b, tmp->val);
		if (i > ft_case_rrarrb_a(a, b, tmp->val))
			i = ft_case_rrarrb_a(a, b, tmp->val);
		if (i > ft_case_rarrb_a(a, b, tmp->val))
			i = ft_case_rarrb_a(a, b, tmp->val);
		if (i > ft_case_rrarb_a(a, b, tmp->val))
			i = ft_case_rrarb_a(a, b, tmp->val);
		tmp = tmp->nxt;
		if (tmp == b)
			break;
	}
	return (i);
}

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.
int	ft_rotate_type_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->val);
	while (42)
	{
		if (i > ft_case_rarb(a, b, tmp->val))
			i = ft_case_rarb(a, b, tmp->val);
		if (i > ft_case_rrarrb(a, b, tmp->val))
			i = ft_case_rrarrb(a, b, tmp->val);
		if (i > ft_case_rarrb(a, b, tmp->val))
			i = ft_case_rarrb(a, b, tmp->val);
		if (i > ft_case_rrarb(a, b, tmp->val))
			i = ft_case_rrarb(a, b, tmp->val);
		tmp = tmp->nxt;
		if (tmp == a)
			break;
	}
	return (i);
}


// This function calculates the required amount of rotation.
// Calculations are done for rra+rrb case.
int	ft_case_rrarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize_circ(a) - ft_find_place_a(a, c);
	if ((i < (ft_lstsize_circ(b) - b->val)) && b->val)
		i = ft_lstsize_circ(b) - b->val;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	ft_case_rarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (b->val)
		i = ft_lstsize_circ(b) - b->val;
	i = ft_find_place_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	ft_case_rrarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize_circ(a) - ft_find_place_a(a, c);
	i = b->val + i;
	return (i);
}