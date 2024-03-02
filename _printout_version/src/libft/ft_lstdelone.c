/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:37 by aschenk           #+#    #+#             */
/*   Updated: 2023/12/01 16:39:40 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes a list element as parameter and deletes its content as well
as free the allocated memory using the del function passed as parameter too.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
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

	// Relinking of nodes before deleting -> wouldn't be able to print otherwise
	node1->next = node2->next;
	ft_lstdelone(node2, free);

	printf("\nAfter deletion:\n");
	print_list(lst);

	while (lst != NULL)
	{
		t_list *temp = lst;
		lst = lst->next;
		free(temp->content);
		free(temp);
	}
	return (0);
}
*/
