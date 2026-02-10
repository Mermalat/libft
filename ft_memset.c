/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:37:23 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 02:54:16 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t          i;
	unsigned char   *ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

#include <stdio.h>

int main()
{
	char str[50] = "Hello, World!";
	printf("Before memset: %s\n", str);
	ft_memset(str, 'x', 5);
	printf("After memset: %s\n", str);
	return 0;
}