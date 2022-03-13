/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:33:56 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/12 02:18:08 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew(int num, int order)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->next = NULL;
	new->prev = NULL;
	new->num = num;
	new->order = order;
	new->flag = 0;
	new->score = 0;
	return (new);
}

void	add_to_stack_a(t_all **all, t_node *elem)
{
	t_node	*last_a;

	// if (!elem)
	// 	free_all(all);
	last_a = (*all)->stack_a;
	if (last_a)
	{
		if (last_a->prev)
		{
			last_a->prev->next = elem;
			elem->prev = last_a->prev;
			last_a->prev = elem;
			elem->next = last_a;
		}
		else
		{
			last_a->next = elem;
			last_a->prev = elem;
			elem->next = last_a;
			elem->prev = last_a;
		}
	}
	else
		(*all)->stack_a = elem;
}

void	create_struct(t_all *all, int size)
{
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = size;
	all->size_b = 0;
	all->min = 0;
	all->max = 0;
	all->med = 0;
	all->flag = 0;
	all->next = 1;
	all->start = 0;
	all->stop = 0;
	all->max_seq = 1;
	all->rev_a = 0;
	all->rev_b = 0;
	all->to_push = 0;
	all->min_score = 0;
	all->order_a = 0;
	all->index = 0;
}

t_all	*init(int *arr, int size)
{
	t_all	*all;
	int		k;
	int		i;
	int		order;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		free(arr);
		exit(1);
	}
	create_struct(all, size);
	i = 0;
	while (i < size)
	{
		k = 0;
		order = 1;
		while (k < size)
		{
			if (arr[i] > arr[k++])
				order++;
		}
		add_to_stack_a(&all, lstnew(arr[i], order));
		i++;
	}
	return (all);
}
