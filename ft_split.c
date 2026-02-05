/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:42:43 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 03:01:04 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}
static int count_words(const char *s, char *sep)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (!is_sep(*s, sep) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*s, sep))
			in_word = 0;
		s++;
	}
	return (count);
}

static int word_length(const char *s, char *sep)
{
	int len = 0;

	while (s[len] && !is_sep(s[len], sep))
		len++;
	return (len);
}

static void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

char **ft_split(char const *s, char *sep)
{	char **words;
	int i = 0;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, sep) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		if (!is_sep(*s, sep))
		{
			int len = word_length(s, sep);
			words[i] = ft_substr(s, 0, len);
			if (!words[i])
				{ 	
					free_words(words, i);
					return (NULL);
				}	
			i++;
			s += len;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words); }