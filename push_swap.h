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

void	choser(t_list **a);
void	alg_3(t_list **lst);
void	alg_big(t_list **lst);
//void	alg_full(t_list *lst);

void	ft_indexify(int *lst, int *tmp, int size);
void	ft_listify(int *lst, int size);
int		ft_check_order(int *lst, int size);
int		ft_check_num(char *arg);
int		ft_check_int(char *arg);

//	ACTIONS

void	swap(t_list **down);
void	rotate(t_list **last);
void	rrotate(t_list **second);
void	push(t_list **stack_o, t_list **stack_d);

//	COMMANDS

void	ft_pa(t_list **b, t_list **a);
void	ft_pb(t_list **a, t_list **b);

void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);

void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);

void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);

//	ALGORITHM UTILS

int		ft_lstsize_circ(t_list *a);
int		ft_check_sorted(t_list *a);
t_list	*ft_lstmax(t_list *a);
t_list	*ft_lstmin(t_list *a);

// SMOOTH
//t_list	*ft_sort_b(t_list **stack_a);
//t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b);

int		ft_find_place_b(t_list *stack_b, int nbr_push);
int		ft_find_place_a(t_list *stack_a, int nbr_push);

int		ft_find_index(t_list *a, int nbr);
int		ft_rotate_type_ba(t_list *stack_a, t_list *stack_b);
int		ft_rotate_type_ab(t_list *stack_a, t_list *stack_b);

int		ft_case_rarb(t_list *a, t_list *b, int c);
int		ft_case_rrarrb(t_list *a, t_list *b, int c);
int		ft_case_rrarb(t_list *a, t_list *b, int c);
int		ft_case_rarrb(t_list *a, t_list *b, int c);
int		ft_case_rarb_a(t_list *a, t_list *b, int c);
int		ft_case_rrarrb_a(t_list *a, t_list *b, int c);
int		ft_case_rarrb_a(t_list *a, t_list *b, int c);
int		ft_case_rrarb_a(t_list *a, t_list *b, int c);

int		use_rarb(t_list **a, t_list **b, int c, char s);
int		use_rrarrb(t_list **a, t_list **b, int c, char s);
int		use_rrarb(t_list **a, t_list **b, int c, char s);
int		use_rarrb(t_list **a, t_list **b, int c, char s);

// DEBUG FUNCTIONS

void	ft_lstprint(t_list *a);

#endif
