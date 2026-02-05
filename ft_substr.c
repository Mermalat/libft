/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:58:42 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 02:53:57 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *sub;

    if (!s)
        return (NULL);
    if (start >= (unsigned int)ft_strlen(s))
        return (ft_strdup(""));
    if (len > (size_t)(ft_strlen(s) - start))
        len = ft_strlen(s) - start;
    sub = (char *)malloc(len + 1);
    if (!sub) 
    // return 0 if malloc fails
        return (0);
    i = 0;
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}