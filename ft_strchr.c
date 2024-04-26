/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:32:35 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/19 11:08:55 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	target;

	i = 0;
	target = (char)c;
	while (s[i])
	{
		if (s[i] == target)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == target)
		return ((char *) &s[i]);
	return (NULL);
}
