/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:33:32 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 02:57:41 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}

#include <stdio.h>

int main()
{
	t_list *head = NULL;
	t_list *new_node = ft_lstnew(ft_strdup("Hello"));
	t_list *new_node2 = ft_lstnew(ft_strdup("World"));
	ft_lstadd_front(&head, new_node);
	printf("First node content: %s\n", (char *)head->content);
	ft_lstadd_front(&head, new_node2);
	printf("Second node content: %s\n", (char *)head->content);
	ft_lstdelone(new_node, free);
	ft_lstdelone(new_node2, free);
	return 0;
}