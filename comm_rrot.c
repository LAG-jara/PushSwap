/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_rrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}