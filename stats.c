/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslanageev <ruslanageev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:05:07 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/06 02:15:40 by ruslanageev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max(t_all *all, t_node *node, int stack_size)
{
	t_node	*tmp;
	int		max;
	int		i;

	tmp = node;
	max = node->order;
	i = 0;
	while (i < stack_size)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
		i++;
	}
	all->max = max;
}

void	min(t_all *all, t_node *node, int stack_size)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = node;
	min = node->order;
	i = 0;
	while (i < stack_size)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
		i++;
	}
	all->min = min;
}

void	med(t_all *all, t_node *node, int stack_size)
{
	max(all, node, stack_size);
	min(all, node, stack_size);
	all->med = (all->max - all->min) / 2 + all->min;
}
