/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:14:45 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 03:12:13 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !del)
		return;
	current = *lst;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*lst = NULL;
}

int main()
{
	t_list *head = NULL;
	t_list *new_node = ft_lstnew(ft_strdup("Hello"));
	t_list *new_node2 = ft_lstnew(ft_strdup("World"));
	ft_lstadd_front(&head, new_node);
	printf("First node content: %s\n", (char *)head->content);
	ft_lstadd_front(&head, new_node2);
	printf("Second node content: %s\n", (char *)head->content);
	ft_lstclear(&head, free);
	return 0;
}