/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:10:08 by merma             #+#    #+#             */
/*   Updated: 2026/01/20 21:55:14 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *new_str;

    if (!s || !f)
        return (NULL);
    new_str = (char *)malloc(ft_strlen(s) + 1);
    if (!new_str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        new_str[i] = f(i, s[i]);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}