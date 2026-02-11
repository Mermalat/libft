/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:43:45 by memalli           #+#    #+#             */
/*   Updated: 2026/02/10 16:43:46 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strmerge(char *dest, const char *src1, const char *src2)
{
	int	i;
	int	len1;
	int	len2;
	int	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(src1);
	len2 = ft_strlen(src2);
	while (i < len1)
	{
		dest[i] = src1[i];
		i++;
	}
	while (j < len2)
	{
		dest[i + j] = src2[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*merged;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	merged = (char *)malloc(len1 + len2 + 1);
	if (!merged)
		return (NULL);
	ft_strmerge(merged, s1, s2);
	return (merged);
}
