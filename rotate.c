/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:30:20 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/03 02:00:46 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_all *all)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->next;
	write(1, "ra\n", 3);
}

void	rb(t_all *all)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->next;
	write(1, "rb\n", 3);
}

void	rr(t_all *all)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		all->stack_b = all->stack_b->next;
		all->stack_a = all->stack_a->next;
	}
	write(1, "rr\n", 3);
}
