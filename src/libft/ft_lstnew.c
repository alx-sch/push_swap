/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:58:59 by aschenk           #+#    #+#             */
/*   Updated: 2023/12/01 14:25:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function dynamically allocates memory for a new element of type t_list,
initializing its content with the provided content parameter. The next pointer
of the newly created element is set to NULL. The function then returns the
pointer to the newly allocated list element
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	// Test 1: Create a new node with integer content
	int content1 = 42;
	t_list *node1 = ft_lstnew(&content1);

	if (!node1)
	{
		printf(stderr, "Test 1 failed: Memory allocation error\n");
		return (1);
	}

	// Test 2: Create a new node with string content
	char *content2 = "Hello, world!";
	t_list *node2 = ft_lstnew(content2);

	if (!node2)
	{
		printf(stderr, "Test 2 failed: Memory allocation error\n");
		return (1);
	}

	// Print the contents of the nodes for verification
	printf("Test 1: %p -> %d\n", (void *)node1, *(int *)node1->content);
	printf("Test 2: %p -> %s\n", (void *)node2, (char *)node2->content);

	// Free the allocated memory
	free(node1);
	free(node2);

	return (0);
}
*/
