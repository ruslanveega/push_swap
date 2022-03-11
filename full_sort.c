/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslanageev <ruslanageev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:53:59 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/10 13:29:29 by ruslanageev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_maxseq(t_all *all, int size)
{
	int		stop;
	int		start;
	int		max_seq;
	t_node	*tmp;


	tmp = all->stack_a;
	start = tmp->prev->order;
	stop = tmp->prev->order;
	max_seq = 0;
	while (size--)
	{
		if (tmp->order == tmp->prev->order + 1)
			stop = tmp->order;
		else
		{
			max_seq = stop - start;
			start = tmp->order;
			stop = tmp->order;
		}
		if (max_seq > all->max_seq)
			all->max_seq = max_seq;
		tmp = tmp->next;
	}
	printf("max seq - %d\n", all->max_seq);
}

void	search_index(t_all *all, int size)
{
	int		stop;
	int		start;
	int		max_seq;
	t_node	*tmp;

	tmp = all->stack_a;
	start = tmp->prev->order;
	stop = tmp->prev->order;
	max_seq = 0;
	while (size--)
	{
		if (tmp->order == tmp->prev->order + 1)
			stop = tmp->order;
		else
		{
			max_seq = stop - start;
			if (max_seq == all->max_seq)
			{
				all->start = start;
				all->stop = stop;
				break;
			}
			start = tmp->order;
			stop = tmp->order;
		}
		tmp = tmp->next;
	}
}

void	full_sort(t_all *all)
{
	search_maxseq(all, 2 * all->size_a);
	search_index(all, 2 * all->size_a);
	max(all, all->stack_a, all->size_a);
	min(all, all->stack_a, all->size_a);
	med(all, all->stack_a, all->size_a);
	while (all->size_a != 3)
	{
		if (all->stack_a->order == all->min || all->stack_a->order == all->max || all->stack_a->order == all->med)
			ra(all);
		else
			pb(all);
	}
	sort_3(all);
	while (all->size_b)
	{
		get_score(all, all->size_b);
		make_descision(all);
		put_a(all);
	}
	while (all->stack_a->order != 1)
	{
		if (all->stack_a->order < all->size_a / 2)
			rra(all);
		else
			ra(all);
	}
}
