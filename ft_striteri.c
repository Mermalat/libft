/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:11:22 by merma             #+#    #+#             */
/*   Updated: 2026/01/20 21:48:23 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int    ctrl;

    if (!s || !f)
        return;
    ctrl = 0;
    while (s[ctrl] != '\0')
    {
        f(ctrl, &s[ctrl]);
        ctrl++;
    }
}