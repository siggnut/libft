/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:32:27 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 16:46:44 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    int i;
    char a[10];

    i = 0;
    if (n == 0)
        write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
    if (n < 0)
    {
        n = -n;
        write(fd, "-", 1);
    }
    while (n > 0)
    {
        a[i++] = (n % 10) + 48;
        n /= 10;
    }
    while (i > 0)
    {    
		write(fd, &a[--i], 1);
	}
}
/*
#include <unistd.h>
int main() {
    int fd = 1; // Standard output (terminal)

    ft_putnbr_fd(12345, fd); // Writes "12345" to standard output
    write(fd, "\n", 1); // Newline for clarity

    ft_putnbr_fd(-12345, fd); // Writes "-12345" to standard output
    write(fd, "\n", 1); // Newline for clarity

    return 0;
}
*/