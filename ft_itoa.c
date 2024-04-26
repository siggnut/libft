/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:07 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 15:24:47 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;//'-' needs space too so less than 0 needs 2?
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
	long	count;//n to long nbr for int min and max?cast n
	long	num;

	num = (long)n;
	count = num_count(n);
	neg = 0;
	i = count - 1; //starting point, right to left
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
		return (str); //possible?
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + '0'; //str[--i]? reverse in same part
		num /= 10;
	}
	if (neg)
		str[i--] = '-';
	//str[count] = '\0';
	return (str);
	 //remainder less than 10 or greater, break into smaller
}
/*
#include <limits.h>
#include <stdio.h>
int main() {
    // Test a single integer conversion
    int test_value = 2147483647;  // You can choose any integer to test

    // Convert the integer to a string using ft_itoa
    char *result = ft_itoa(test_value);

    if (result) {
        printf("ft_itoa(%d) -> %s\n", test_value, result);  // Print the converted result
        free(result);  // Free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;  // Indicate successful program execution
}

int to string, strlen + malloc?
neg must be handled
overflow?
num / 10
num % 10 + '0', num /= 10
reverse?
malloc -> count digits
  while (nbr != 0)
    {
        result[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i--;
    }
*/