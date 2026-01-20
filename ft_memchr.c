/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:40:00 by merma             #+#    #+#             */
/*   Updated: 2026/01/18 18:09:03 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t          i;
    const unsigned char *ptr;

    ptr = (const unsigned char *)s; // Dizi icerisinde int c degerini byte olarak ariyor.
    i = 0;
    while (i < n)
    {
        if (ptr[i] == (unsigned char)c) // Bellek byte byte gezilirken unsigned char kullanilir
            return ((void *)(ptr + i));
        i++;
    }
    return (0);
}