/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **b, t_list **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	ft_pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	ft_sa(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}