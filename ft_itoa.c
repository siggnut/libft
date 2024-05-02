/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:07 by shyvonen          #+#    #+#             */
/*   Updated: 2024/05/02 13:42:23 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(long num)
{
	int		count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*alloc_size(int count)
{
	char	*temp;

	temp = (char *)malloc((count + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	num;
	long	count;

	num = (long)n;
	count = num_count(num);
	i = count - 1;
	result = alloc_size(count);
	if (!result)
		return (NULL);
	result[count] = '\0';
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	while (num)
	{
		result[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
