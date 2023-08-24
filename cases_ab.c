/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			break ;
	}
	return (i);
}

int	ft_case_rarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

int	ft_case_rrarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize_circ(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize_circ(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize_circ(a) - ft_find_index(a, c);
	return (i);
}

int	ft_case_rrarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize_circ(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

int	ft_case_rarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize_circ(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
