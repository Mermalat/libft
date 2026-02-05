/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:58:17 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 00:55:12 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
    size_t total_size;
    void *ptr;
    size_t i;

    total_size = count * size;
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < total_size)
    {
        ((unsigned char *)ptr)[i] = 0;
        i++;
    }
    return (ptr);
}