/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **down)
{
	t_list	*up;

	up = (*down)->nxt;
	if (up != (*down))
	{
		if ((*down)->pre != up)
		{
			(*down)->pre->nxt = up;
			up->nxt->pre = *down;
		}
		(*down)->nxt = up->nxt;
		up->nxt = *down;
		up->pre = (*down)->pre;
		(*down)->pre = up;
	}
	*down = up;
}

void	rotate(t_list **last)
{
	*last = (*last)->nxt;
}

void	rrotate(t_list **second)
{
	*second = (*second)->pre;
}

// Push grabs the origin stack(stack_o) and put it on destiny stack(stack_d)
// Returns the stack whom is pushed. To not lose our origin stack we have to 
//have locate the save the stack_o->nxt before to use push unless its itself
void	push(t_list **stack_o, t_list **stack_d)
{
	t_list	*nxt_o;

	if (!stack_o)
		return ;
	nxt_o = (*stack_o)->nxt;
	if (nxt_o == (*stack_o))
		nxt_o = NULL;
	(*stack_o)->pre->nxt = (*stack_o)->nxt;
	(*stack_o)->nxt->pre = (*stack_o)->pre;
	if (*stack_d)
	{
		(*stack_d)->pre->nxt = (*stack_o);
		(*stack_o)->nxt = (*stack_d);
		(*stack_o)->pre = (*stack_d)->pre;
		(*stack_d)->pre = (*stack_o);
	}
	else
	{
		(*stack_o)->nxt = (*stack_o);
		(*stack_o)->pre = (*stack_o);
	}
	(*stack_d) = (*stack_o);
	*stack_o = nxt_o;
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/