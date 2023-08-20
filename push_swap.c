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
	ft_printf("Error\n");
	free(*ptr);
	*ptr = NULL;
	return (-1);
}

void    ft_sort(int *lst, int size)
{	
	int i;
	int j;
	int *tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
	{
		lst[0] = -1;
		return ;
	}
	j = -1;
	while (++j < size)
	{
		i = -1;
		tmp[j] = 0;
		while (++i < size)
		{
			if (lst[i] < lst[j])
				tmp[j] += 1;
			if (lst[i] == lst[j] && i != j)
				tmp[0] = -1;                
		}
	}
	i = -1;
	while(++i < size)
		lst[i] = tmp[i];
	free (tmp);
}

int	main(int ac, char **av)
{
	int i;
	int *lst; //lista de ac tamaño

	i = 0;
	if (ac < 2)
		return (0);
	lst = malloc(sizeof(int) * ac - 1);
	while(++i < ac)
	{
		if(!ft_check_num(av[i]))    //in case of error promp Error\n
			return (ft_error(&lst));
		lst[i - 1] = ft_atoi(av[i]);
	}
	ft_sort(lst, ac - 1);
	if (lst[0] == -1)
		return (ft_error(&lst));
	if(ft_check_order(lst, ac - 1))
		return (0);
	i = -1;
	ft_listify(lst, ac - 1);
	/*
	while (++i < ac - 1)
		ft_printf("%d\n", lst[i]);
	*/
	return (0); 
}
