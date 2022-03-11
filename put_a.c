/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslanageev <ruslanageev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 02:30:17 by ruslanageev       #+#    #+#             */
/*   Updated: 2022/03/10 15:01:17 by ruslanageev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_b(t_all *all)
{
	if (all->rev_b)
		rrb(all);
	else
		rb(all);
}

void	rot_a(t_all *all)
{
	if (all->rev_a)
		rra(all);
	else
		ra(all);
}

void	rot_a_b(t_all *all)
{
	if (all->rev_a && all->rev_b)
		rrr(all);
	else if (!(all->rev_a) && !(all->rev_b))
		rr(all);
	else
	{
		rot_a(all);
		rot_b(all);
	}
}

void	put_a(t_all *all)
{
	while (all->stack_a->order != all->order_a \
			|| all->stack_b->order != all->to_push)
	{
		if (all->stack_a->order == all->order_a)
			rot_b(all);
		else if (all->stack_b->order == all->to_push)
			rot_a(all);
		else
			rot_a_b(all);
	}
	pa(all);
}

