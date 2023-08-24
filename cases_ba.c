/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_ba.c                                         :+:      :+:    :+:   */
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
			break ;
	}
	return (i);
}

int	ft_case_rarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

int	ft_case_rrarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize_circ(a) - ft_find_place_a(a, c);
	if ((i < (ft_lstsize_circ(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = ft_lstsize_circ(b) - ft_find_index(b, c);
	return (i);
}

int	ft_case_rarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (b->val)
		i = ft_lstsize_circ(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

int	ft_case_rrarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize_circ(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
