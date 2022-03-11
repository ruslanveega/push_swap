/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:52:37 by fcassand          #+#    #+#             */
/*   Updated: 2022/02/03 13:03:43 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elem_error(char *str)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd("Incorrect arguments - ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	dup_error(int *arr)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	free(arr);
	ft_putstr_fd("Duplicate numbers\n", 2);
	exit(1);
}

void	value_error(void)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd("Arguments must be less than \
Max Integer and more than Min Integer\n", 2);
	exit(1);
}

void	sorted(void)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd("Array is already sorted\n", 2);
	exit(1);
}

void	arg_error()
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd("At least should be one argument!\n", 2);
	exit(1);
}
