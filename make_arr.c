/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslanageev <ruslanageev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:47:00 by fcassand          #+#    #+#             */
/*   Updated: 2022/03/06 02:12:30 by ruslanageev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_char(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	*get_arr(char **av, int size, int ac)
{
	char	**numbers;
	int		*arr;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		numbers = ft_split(av[i++], ' ');
		while (numbers[j])
		{
			if (ft_atoi(numbers[j]) >= MAXINT || ft_atoi(numbers[j]) <= MININT)
				value_error();
			arr[k] = ft_atoi(numbers[j++]);
			k++;
		}
		free_char(numbers);
	}
	return (arr);
}

int	check_elem(char *elem)
{
	char	**numbers;
	int		i;
	int		size_elem;

	size_elem = 0;
	i = 0;
	numbers = ft_split(elem, ' ');
	while (numbers[i])
	{
		if (!ft_atoi(numbers[i]))
			return (free_char(numbers));
		size_elem++;
		i++;
	}
	return (size_elem);
}

int	check_dup(int *arr, int size)
{
	int	i;
	int	k;

	k = 0;
	while (k < size)
	{
		i = k + 1;
		while (i < size)
		{
			if (arr[k] == arr[i])
				return (1);
			i++;
		}
		k++;
	}
	return (0);
}

int	check_and_make(char **av, int ac, int **arr)
{
	int	i;
	int	size;
	int	size_elem;

	i = 1;
	size = 0;
	while (i < ac)
	{
		size_elem = check_elem(av[i]);
		if (size_elem)
			size += size_elem;
		else
			elem_error(av[i]);
		i++;
	}
	*arr = get_arr(av, size, ac);
	if (check_dup(*arr, size))
		dup_error(*arr);
	return (size);
}
