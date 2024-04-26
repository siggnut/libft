/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:38:37 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/25 15:27:06 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //header only if called other lib funtions!
/*size_t	needle_len;

	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && needle_len <= len) //i?
	{
		if (needle[i] == haystack[i]) //strncmp?
	}*/
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len) //i < len i + j < len
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len) // i + j < len or <= len
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		//j = 0;
		i++;
		//len--;
	}
	return (NULL);
}

/*int main()
{
    // Test cases
    const char *haystack = "aaaaaxxx";
    const char *needle1 = "xxx"; // Present in haystack
    const char *needle2 = "not found"; // Not present in haystack
    const char *needle3 = ""; // Empty needle
    const char *needle4 = "aa"; // Near the end of haystack
    const char *needle5 = "xxx"; // Within the first 20 characters
    cacasta
    aaxxz
    aaxxc

    // Testing cases
    char *result;

    // Test 1: Basic search within the entire length of the haystack
    result = ft_strnstr(haystack, needle1, 20);
    if (result)
        printf("Test 1: Found '%s' at position %ld\n", needle1, result - haystack);
    else
        printf("Test 1: '%s' not found\n", needle1);

    // Test 2: Searching for a non-existing substring
    result = ft_strnstr(haystack, needle2, strlen(haystack));
    if (result)
        printf("Test 2: Found '%s' at position %ld\n", needle2, result - haystack);
    else
        printf("Test 2: '%s' not found\n", needle2);

    // Test 3: Empty needle
    result = ft_strnstr(haystack, needle3, strlen(haystack));
    if (result)
        printf("Test 3: Found an empty needle, so returning the start of the haystack: '%s'\n", result);

    // Test 4: Search with limited length (finding 'strnstr')
    result = ft_strnstr(haystack, needle4, strlen(haystack)); // Not the full length of haystack
    if (result)
        printf("Test 4: Found '%s' at position %ld within limited length\n", needle4, result - haystack);
    else
        printf("Test 4: '%s' not found within the specified length\n", needle4);

    // Test 5: Finding 'for' within the first 20 characters
    result = ft_strnstr(haystack, needle5, 2); // Limited length, but 'for' is inside
    if (result)
        printf("Test 5: Found '%s' at position %ld within limited length\n", needle5, result - haystack);
    else
        printf("Test 5: '%s' not found within the specified length\n", needle5);

    return 0;
}*/