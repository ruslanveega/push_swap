/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:34:59 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/23 01:38:37 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_ad;

	str_ad = malloc(sizeof(char) * ft_strlen((char *)str) + 1);
	if (str_ad == NULL)
		return (NULL);
	ft_memcpy(str_ad, str, ft_strlen((char *)str) + 1);
	return (str_ad);
}
