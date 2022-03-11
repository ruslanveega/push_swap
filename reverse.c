/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:13:43 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/03 02:01:29 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_all *all)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_all *all)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		all->stack_b = all->stack_b->prev;
		all->stack_a = all->stack_a->prev;
	}
	write(1, "rrr\n", 4);
}
