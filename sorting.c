/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:28:28 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/04 01:13:33 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_all *all)
{
	if (all->stack_a->num > all->stack_a->next->num)
	{
		if (all->stack_a->num < all->stack_a->prev->num)
		{
			sa(all);
			return ;
		}
		ra(all);
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all);
	}
	else
	{
		if (all->stack_a->num < all->stack_a->prev->num)
		{
			rra(all);
			sa(all);
		}
		else
			rra(all);
	}
}

void	sort_5(t_all *all)
{
	while (all->size_a != 3)
	{
		if (all->stack_a->order < 3)
			pb(all);
		else
			ra(all);
	}
	sort_3(all);
	if (all->stack_b->num < all->stack_b->next->num)
	{
		sb(all);
		pa(all);
	}
	else
		pa(all);
	pa(all);
}

void	sorting(t_all *all)
{
	if (all->size_a == 2)
		sa(all);
	else if (all->size_a == 3)
		sort_3(all);
	else if (all->size_a <= 5)
		sort_5(all);
	else
		full_sort(all);
}

