/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:07 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 17:53:49 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;
	long	count;
	long	num;

	num = (long)n;
	count = num_count(n);
	neg = 0;
	i = count - 1;
	str = (char *)malloc(count + 1);
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	if (num == 0)
	{
		str[i] = '0';
		return (str);
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	if (neg)
		str[i--] = '-';
	return (str);
}
