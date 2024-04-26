/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:22:15 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:32 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// strings[0] = "Dynamic";  // First string
//    strings[1] = "Allocation";  // Second string
//    strings[2] = NULL;  // null
/*iterate through s if c found split save into array or strigns
if (strings == NULL) return null
strdup to save into array
split into many? array for words in s, 
steps?
iterate string, if meet deliminator count of s goes up, so we know how many string in array, how many separators
separate func for splitting, conditions?
fill new strings w the splitted, allocate memory
free
*/
static int	word_count(const char *s, char c)
{
	int	count;
	int	sep;

	count = 0;
	sep = 0;
	while (*s)
	{
		if (*s != c && sep == 0)
		{
			sep = 1;
			count++;
		}
		else if (*s == c)
		{
			sep = 0;
		}
		s++;
	}
	return (count);
}

static void	*ft_free(char **strings, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static void	splitting_string(const char *s, char c, char **strings, size_t *j)
{
	size_t		len;
	size_t		i;
	size_t		start;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		start = i;
		while (i < len && s[i] != c)
			i++;
		if (i > start)
		{
			strings[*j] = ft_substr(s, start, i - start);
			if (strings[*j] == NULL)
			{
				ft_free(strings, *j);
			}
			(*j)++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	j;
	size_t	words;

	j = 0;
	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	strings = (char **)malloc((words + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	splitting_string(s, c, strings, &j);
	strings[j] = (NULL);
	return (strings);
}
