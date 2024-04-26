/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:24:02 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 17:53:59 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		result;
	unsigned char		*s1;

	s1 = (unsigned char *)s;
	result = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == result)
			return ((void *) &s1[i]);
		i++;
	}
	return (NULL);
}
