/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:22:15 by shyvonen          #+#    #+#             */
/*   Updated: 2024/05/11 18:25:18 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_free(char **strings, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		strings[i] = NULL;
		i++;
	}
	free(strings);
	strings = NULL;
}

static int	splitting_string(const char *s, char c, char **strings, size_t j)
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
			strings[j] = ft_substr(s, start, i - start);
			if (strings[j] == NULL)
			{
				ft_free(strings, j);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	words;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	strings = ft_calloc((words + 1), sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (!splitting_string(s, c, strings, j))
		return (NULL);
	return (strings);
}
