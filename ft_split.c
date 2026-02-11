/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:42:59 by memalli           #+#    #+#             */
/*   Updated: 2026/02/11 19:11:06 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
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
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_words(char **words, int i)
{
	while (i >= 0)
		free(words[i--]);
	free(words);
}

static char	**ft_createwords(const char *mainstr, char **words, char sep)
{
	int	i;
	int	len;

	i = 0;
	while (*mainstr)
	{
		if (*mainstr != sep)
		{
			len = word_length(mainstr, sep);
			words[i] = ft_substr(mainstr, 0, len);
			if (!words[i])
			{
				free_words(words, i - 1);
				return (NULL);
			}
			i++;
			mainstr += len;
		}
		else
			mainstr++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	words = ft_createwords(s, words, c);
	return (words);
}
