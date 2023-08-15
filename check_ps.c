/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:30:34 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 18:30:37 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_num(char *arg)
{
	int i;
	
	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		++i;
	while(arg[i] == '0')
		i++;
	while (arg[++i])
	{
		if (!(arg[i] <= '9' && arg[i] >= '0'))
			return (0);
	}
	return (ft_check_int(arg));
}

int	ft_check_int(char *arg)
{
	int		len;
	char	sign;

	if (*arg == '-' || *arg == '+')
	{
		sign = *arg;
		arg++;
	}
	while(*arg == '0')
		arg++;
	len = ft_strlen(arg);
	if (len > 10)
		return (0);
	if (len == 10)
	{
		if(sign == '-')
			len = ft_strncmp(arg,"2147483648", 10);
		else
			len = ft_strncmp(arg,"2147483647", 10);
		if(len > 0)
			return (0);
	}
	return (1);
}
