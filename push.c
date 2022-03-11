/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:30:17 by fcassand          #+#    #+#             */
/*   Updated: 2022/02/23 02:09:36 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_all *all)
{
	t_node	*tmp;

	tmp = all->stack_b->next;
	all->stack_b->next->prev = all->stack_b->prev;
	all->stack_b->prev->next = all->stack_b->next;
	if (all->stack_a)
	{
		all->stack_b->next = all->stack_a;
		all->stack_b->prev = all->stack_a->prev;
		all->stack_a->prev->next = all->stack_b;
		all->stack_a->prev = all->stack_b;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->prev = all->stack_a;
	}
	all->stack_b = tmp;
}

void	pa(t_all *all)
{
	if (all->stack_b == NULL)
		return ;
	push_a(all);
	if (all->size_b == 1)
		all->stack_b = NULL;
	all->size_a++;
	all->size_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_all *all)
{
	t_node	*tmp;

	tmp = all->stack_a->next;
	all->stack_a->next->prev = all->stack_a->prev;
	all->stack_a->prev->next = all->stack_a->next;
	if (all->stack_b)
	{
		all->stack_a->next = all->stack_b;
		all->stack_a->prev = all->stack_b->prev;
		all->stack_b->prev->next = all->stack_a;
		all->stack_b->prev = all->stack_a;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_b->next = all->stack_b;
		all->stack_b->prev = all->stack_b;
	}
	all->stack_a = tmp;
}

void	pb(t_all *all)
{
	if (all->stack_a == NULL)
		return ;
	push_b(all);
	if (all->size_a == 1)
		all->stack_a = NULL;
	all->size_b++;
	all->size_a--;
	write(1, "pb\n", 3);
}
