/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:58:17 by merma             #+#    #+#             */
/*   Updated: 2026/02/05 03:23:05 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	heap = malloc(count * size);
	if (!heap)
		return (NULL);
	ft_bzero(heap, count * size);
	return (heap);
}