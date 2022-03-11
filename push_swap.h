/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslanageev <ruslanageev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:25:48 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/10 14:28:28 by ruslanageev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define MAXINT 2147483647
# define MININT -2147483648

typedef	struct	s_node
{
	int				num;
	int				order;
	int				flag;
	int				score;
	struct	s_node	*next;
	struct	s_node	*prev;
}				t_node;

typedef	struct	s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				med;
	int				flag;
	int				next;
	int				start;
	int				stop;
	int				max_seq;
	int				rev_a;
	int				rev_b;
	int				to_push;
	int				min_score;
	int				order_a;
}					t_all;

int		main(int argc, char **argv);
int		check_and_make(char **av, int ac, int **arr);
int		check_elem(char *elem);
int		*get_arr(char **av, int size, int ac);
int		free_char(char	**str);
void	elem_error(char *str);
int		check_dup(int *arr, int size);
void	dup_error(int *arr);
void	value_error(void);
int		is_sorted(int *arr, int	size);
void	sorted(void);
void	arg_error();
t_all	*init(int *arr, int size);
void	create_struct(t_all *all, int size);
void	add_to_stack_a(t_all **all, t_node *elem);
t_node	*lstnew(int num, int order);
void	ra(t_all *all);
void	rb(t_all *all);
void	rr(t_all *all);
void	rra(t_all *all);
void	rrb(t_all *all);
void	rrr(t_all *all);
void	print_stack(t_all *all);
void	sa(t_all *all);
void	sb(t_all *all);
void	ss(t_all *all);
void	push_a(t_all *all);
void	push_b(t_all *all);
void	pa(t_all *all);
void	pb(t_all *all);
void	sort_3(t_all *all);
void	sorting(t_all *all);
void	sort_5(t_all *all);
void	full_sort(t_all *all);
void	search_maxseq(t_all *all, int size);
void	search_index(t_all *all, int size);
void	get_score(t_all *all, int size);
int		commpare(t_all *all, int order, int size);
void	max(t_all *all, t_node *node, int stack_size);
void	min(t_all *all, t_node *node, int stack_size);
void	med(t_all *all, t_node *node, int stack_size);
void	make_descision(t_all *all);
void	choose_element_a(t_all *all, int size_a, int order);
void	put_a(t_all *all);
void	rot_a_b(t_all *all);
void	rot_a(t_all *all);
void	rot_b(t_all *all);
#endif
