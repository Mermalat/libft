/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:49:34 by merma             #+#    #+#             */
/*   Updated: 2026/01/18 21:22:02 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return str;
}

char	*ft_itoa(int n)
{
	int i;
	int ctrl;
	char *tmp;

	i = 0;
	ctrl = 0;
	tmp = malloc(sizeof(char) * 12);
	if (tmp == NULL || n == 0)
		return ((n == 0) ? "0" : NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		ctrl = 1;
		n *= -1;
	}
	while (n)
	{
		tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (ctrl)
		tmp[i] = '-';
	return ft_strrev(tmp);
}

// int	main(void)
// {
// 	int i = 0;
// 	int tab[5] = {-2147483648, -42, 0, 42, 2147483647};

// 	while (i < 5)
// 		printf("%s\n", ft_itoa(tab[i++]));

// 	return 0;
// }