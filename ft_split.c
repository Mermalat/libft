/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:42:43 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 03:44:00 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int len = 0;

	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_words(char **words, int i)
{
	while (i >= 0)
		free(words[i--]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_length(s, c);
			words[i] = ft_substr(s, 0, len);
			if (!words[i])
				return (free_words(words, i - 1));
			i++;
			s += len;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}