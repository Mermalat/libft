/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:16:28 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 03:11:04 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
#include <stdio.h>

void print_content(void *content)
{
	printf("Node content: %s\n", (char *)content);
}

int main()
{
	t_list *head = NULL;
	t_list *new_node = ft_lstnew(ft_strdup("Hello"));
	t_list *new_node2 = ft_lstnew(ft_strdup("World"));
	ft_lstadd_front(&head, new_node2);
	ft_lstadd_front(&head, new_node);
	ft_lstiter(head, print_content);
	ft_lstdelone(new_node, free);
	ft_lstdelone(new_node2, free);
	return 0;
}