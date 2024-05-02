/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:18:26 by shyvonen          #+#    #+#             */
/*   Updated: 2024/05/02 17:07:41 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total;

	total = size * count;
	if ((count && total / count != size) || total > SIZE_MAX)
		return (NULL);
	result = malloc(total);
	if (!result)
		return (NULL);
	ft_bzero (result, total);
	return (result);
}
