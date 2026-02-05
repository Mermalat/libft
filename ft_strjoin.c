/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:18:17 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 02:54:38 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_stroin(const char *s1, const char *s2)
{
    size_t  len1;
    size_t  len2;
    char    *merged;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    merged = (char *)malloc(len1 + len2 + 1);
    if (!merged)
        return (0);
    i = 0;
    while (i < len1)
    {
        merged[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
    {
        merged[i + j] = s2[j];
        j++;
    }
    merged[i + j] = '\0';
    return (merged);
}