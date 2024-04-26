/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:53:06 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/26 15:24:17 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

    if (s == NULL)
        return (NULL);
	s_len = ft_strlen(s); //what if !s
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)//if !substr
		return (NULL);
	ft_memcpy (substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int main(void) {
    const char *source = "Hello, World!";
    
    // Test case: Normal substring
    char *substr1 = ft_substr(source, 7, 5);
    printf("Test 1: %s\n", substr1);  // Expected: "World"
    
    // Test case: Start is at the end of the source string
    char *substr2 = ft_substr(source, 13, 5);
    printf("Test 2: %s\n", substr2);  // Expected: ""
    
    // Test case: Start is beyond the source string
    char *substr3 = ft_substr(source, 20, 5);
    printf("Test 3: %s\n", substr3);  // Expected: ""
    
    // Test case: Substring extends beyond the source string
    char *substr4 = ft_substr(source, 7, 10);
    printf("Test 4: %s\n", substr4);  // Expected: "World!"
    
    // Test case: Start at the beginning with length 0
    char *substr5 = ft_substr(source, 0, 0);
    printf("Test 5: %s\n", substr5);  // Expected: ""

    // Free the allocated memory for substrings to avoid memory leaks
    free(substr1);
    free(substr2);
    free(substr3);
    free(substr4);
    free(substr5);

    return 0;  // Indicate successful completion of the program
}*/
////substring from s, iterate until len, start index to copy? from
//allocate mem for substring, string copy?(memcpy?)

