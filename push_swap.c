/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:33:05 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:33:36 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int **ptr)
{
	write(2, "Error\n", 6);
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (-1);
}

void	ft_malloced(int *a)
{
	if (a)
		return ;
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int ac, char **av)
{
	int	i;
	int	*lst;
	int	*tmp; 

	i = 0;
	if (ac < 2)
		return (0);
	lst = malloc(sizeof(int) * ac - 1);
	ft_malloced(lst);
	while (++i < ac)
	{
		if (!ft_check_num(av[i]))
			return (ft_error(&lst));
		lst[i - 1] = ft_atoi(av[i]);
	}
	tmp = malloc(sizeof(int) * ac - 1);
	ft_malloced(tmp);
	ft_indexify(lst, tmp, ac - 1);
	if (lst[0] == -1)
		return (ft_error(&lst));
	if (ft_check_order(lst, ac - 1))
		return (0);
	i = -1;
	ft_listify(lst, ac - 1);
	return (0); 
}
