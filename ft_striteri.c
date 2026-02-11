/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:43:34 by memalli           #+#    #+#             */
/*   Updated: 2026/02/10 16:43:35 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	ctrl;

	if (!s || !f)
		return ;
	ctrl = 0;
	while (s[ctrl] != '\0')
	{
		f(ctrl, &s[ctrl]);
		ctrl++;
	}
}
