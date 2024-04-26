/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:50:32 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 17:53:13 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static long	digits(const char *str, int sign)
{
	long	result;
	long	check;

	result = 0;
	check = 0;
	while (*str && ft_isdigit(*str))
	{
		check = result;
		result = result * 10 + (*str - '0');
		if (sign == 1 && check > result)
			return (-1);
		else if (sign == -1 && check > result)
			return (0);
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str && ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = digits(str, sign);
	return ((int)result * sign);
}
