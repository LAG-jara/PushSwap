/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:34:22 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 13:50:29 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;*/

void	alg_3(t_list *lst, int fun);
void	alg_4(t_list *lst);
//void	alg_5(t_list *lst);
//void	alg_full(t_list *lst);

void	ft_listify(int *lst, int size);
int		ft_check_ordered(int *lst, int size);
int 	ft_check_num(char *arg);
int		ft_check_int(char *arg);

#endif
