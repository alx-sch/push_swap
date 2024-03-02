/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:35:36 by aschenk           #+#    #+#             */
/*   Updated: 2023/12/01 16:42:28 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Deletes and frees the given node and every successor of that node, using the
function ’del’ and free(3). Finally, the pointer to the list must be set
to NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}

/*
#include <stdio.h>

void	print_list(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		printf("%p -> %s\n", (void *)current, (char *)(current->content));
		current = current->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *lst = NULL;

	t_list *node1 = ft_lstnew(ft_strdup("ONE"));
	t_list *node2 = ft_lstnew(ft_strdup("TWO"));
	t_list *node3 = ft_lstnew(ft_strdup("THREE"));

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);

	printf("Before deletion:\n");
	print_list(lst);

	ft_lstclear(&lst, free);

	printf("\nAfter deletion:\n");
	print_list(lst);

	return (0);
}
*/
