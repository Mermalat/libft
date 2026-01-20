/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:26:49 by merma             #+#    #+#             */
/*   Updated: 2026/01/18 18:09:03 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t	i;
    size_t	dst_len;
    size_t	src_len;

    dst_len = 0;
    src_len = 0;
    while (dst[dst_len] && dst_len < dstsize)
        dst_len++;
    while (src[src_len])
        src_len++;
    if (dstsize == 0)
        return (src_len);
    if (dstsize <= dst_len)
        return (src_len + dstsize);
    i = 0;
    while (src[i] && (dst_len + i) < (dstsize - 1))
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}