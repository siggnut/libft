/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:50:32 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 17:50:03 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//bc original uses strol->should use long?https://opensource.apple.com/source/Libc/Libc-186/stdlib.subproj/atoi.c.auto.html but input is int
//lib undefined behavior but when u test against lib atoi answer is different, so handle overflow?
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

/*int main(void) {
    // Test cases to cover different scenarios
    const char *test_cases[] = {
        "42",           // simple positive integer
        "-42",          // negative integer
        "+42",          // positive with explicit sign
        "   42",        // leading spaces
        "  -42",        // leading spaces with negative
        "123abc",       // mixed alphanumeric, should stop at non-digit
        "abc123",       // non-digits at the beginning, should return 0
        "++42",         // invalid double signs, should return 0
        "--42",         // invalid double negative, should return 0
        "+-42",         // mixed signs, should return 0
        "-21474836481111111111111111111111111111111111",            // zero
        "  \t\n\r123",   // spaces and other whitespace
        "–2147483648",
        "2147483647"
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int i;

    for (i = 0; i < num_cases; i++) {
        const char *input = test_cases[i];

        int lib_atoi_result = atoi(input);
        int custom_atoi_result = ft_atoi(input);

        if (lib_atoi_result == custom_atoi_result) {
            printf("PASS: '%s' -> lib_atoi: %d, ft_atoi: %d\n", input, lib_atoi_result, custom_atoi_result);
        } else {
            printf("FAIL: '%s' -> lib_atoi: %d, ft_atoi: %d\n", input, lib_atoi_result, custom_atoi_result);
        }
    }

    return 0;
}*/