/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:19:27 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 02:49:37 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
    size_t  start;
    size_t  end;
    char    *trimmed;

    if (!s1 || !set)
        return (NULL);
    start = 0;
    end = ft_strlen(s1);
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    trimmed = ft_substr(s1, start, end - start);
    return (trimmed); 
}

#include <stdio.h>

int main()
{
    const char *s1 = "  dcba Hello, World! ab  ccdddababc  ";
    const char *set = " abcd";
    char *result = ft_strtrim(s1, set);
    printf("Original: '%s'\n", s1);
    printf("Trimmed: '%s'\n", result);
    free(result);
    return 0;
}