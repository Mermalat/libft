/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:51:10 by merma             #+#    #+#             */
/*   Updated: 2026/01/20 21:55:11 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *s, const char *tofind, size_t len)
{
    size_t  i;
    size_t  j;

    if (*tofind == '\0')
        return ((char *)s);
    i = 0;
    while (s[i] && i < len)
    {
        j = 0;
        while (tofind[j] && (i + j) < len && s[i + j] == tofind[j])
            j++;
        if (tofind[j] == '\0')
            return ((char *)(s + i));
        i++;
    }
    return (0);
}