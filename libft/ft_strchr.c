/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:53:53 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/28 18:11:21 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	while (*str)
	{
		if (*str == (const char)n)
			return ((char *)str);
		str++;
	}
	if (*str == (const char)n)
		return ((char *)str);
	return (NULL);
}
