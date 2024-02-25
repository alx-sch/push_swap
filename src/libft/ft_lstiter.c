/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:57:30 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/30 18:44:20 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

void	print_node(void *content)
{
	printf("[%p] -> %s\n", (void *)content, (char *)content);
}

int	main(void)
{
	t_list *node1 = ft_lstnew("One");
	t_list *node2 = ft_lstnew("Two");
	t_list *node3 = ft_lstnew("Three");

	node1->next = node2;
	node2->next = node3;

	ft_lstiter(node1, print_node);

	return (0);
}
*/
