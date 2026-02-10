/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:17:31 by merma             #+#    #+#             */
/*   Updated: 2026/02/10 03:18:28 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstmapi(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = new_content;
		new_node->next = NULL;
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

#include <stdio.h>

void *duplicate_content(void *content)
{
	
	char *str = (char *)content;
	str+=1;
	return ft_strdup(str);
}

int main()
{
	t_list *head = NULL;
	t_list *new_node = ft_lstnew(ft_strdup("Hello"));
	t_list *new_node2 = ft_lstnew(ft_strdup("World"));
	ft_lstadd_front(&head, new_node);
	printf("First node content: %s\n", (char *)head->content);
	ft_lstadd_front(&head, new_node2);
	printf("New First Content: %s\n", (char *)head->content);
	t_list *new_list = ft_lstmapi(head, duplicate_content, free);
	t_list *current = new_list;
	while (current)
	{
		printf("New list content: %s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstdelone(new_node, free);
	ft_lstdelone(new_node2, free);
	return 0;
}