/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:49:55 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 17:48:48 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	target;
	char	*result;

	i = 0;
	result = NULL;
	target = (char)c;
	while (s[i])
	{
		if (s[i] == target)
		{
			result = (char *) &s[i];
		}
		i++;
	}
	if (s[i] == target)
		result = (char *) &s[i];
	return (result);
}
