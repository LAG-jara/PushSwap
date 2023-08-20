/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates how many times 
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	ft_case_rarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < a->val)
		i = a->val;
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int	ft_case_rrarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize_circ(b) - ft_find_place_b(b, c);
	//ft_printf("rrarrb case\n");
	if ((i < (ft_lstsize_circ(a) - a->val)) && a->val)
		i = ft_lstsize_circ(a) - a->val;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	ft_case_rrarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (a->val)
		i = ft_lstsize_circ(a) - a->val;
	i = ft_find_place_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	ft_case_rarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize_circ(b) - ft_find_place_b(b, c);
	i = a->val + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rb case.
int	ft_case_rarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < b->val)
		i = b->val;
	return (i);
}
