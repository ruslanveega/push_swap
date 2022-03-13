/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:02:15 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/11 23:11:54 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *arr, int size)
{
	int	i;
	int	k;
	int	sorted;

	sorted = 1;
	i = 0;
	while (i < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (arr[k++] < arr[i])
				sorted = 0;
		}
		i++;
	}
	return (sorted);
}

void	print_stack(t_all *all)
{
	int i;

	i = 0;
	while (i < all->size_a)
	{
		all->stack_a = all->stack_a->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		*arr;
	int		size;

	if (argc < 2)
		arg_error();
	size = check_and_make(argv, argc, &arr);
	is_sorted(arr, size);
	if (is_sorted(arr, size))
		sorted();
	all = init(arr, size);
	sorting(all);
	free(arr);

	return (0);
}
