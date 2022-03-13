/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:53:59 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/13 03:08:44 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_sort(t_all *all)
{
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
