/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:45:06 by aschenk           #+#    #+#             */
/*   Updated: 2023/12/01 17:53:18 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This functions works similarly as the ft_lstiter function, but it creates a new
list resulting of the successive applications of f on each element's content.

ft_lstmapclear() is only used to for the sole purpose of making ft_lstmap() one
line shorter and thus Norminette-conform ;)
*/

#include "libft.h"

static void	ft_lstmapclear(t_list *result, void (*del)(void *), void *temp)
{
	ft_lstclear(&result, del);
	del(temp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;
	void	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		if (temp == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		new = ft_lstnew(temp);
		if (new == NULL)
		{
			ft_lstmapclear(result, del, temp);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}

/*
// compile with:
// cc ft_lstmap.c ft_lstnew.c ft_lstadd_back.c ft_lstiter.c ft_toupper.c
//	ft_lstclear.c ft_strlen.c ft_lstdelone.c
#include <stdio.h>

void	print_node(void *content)
{
	printf("[%p] -> %s\n", (void *)content, (char *)content);
}

void	*toupper_mapping(void *content)
{
	char	*str;
	size_t	len;
	char	*result;
	size_t	i;

	str = (char *)content;
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = ft_toupper(str[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	main(void)
{
	t_list	*lst = NULL;

	t_list	*node1 = ft_lstnew("One");
	t_list	*node2 = ft_lstnew("Two");
	t_list	*node3 = ft_lstnew("Three");

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);

	printf("Original List:\n");
	ft_lstiter(lst, print_node);

	t_list *mapped_lst = ft_lstmap(node1, toupper_mapping, free);
	if (mapped_lst == NULL)
		return (1);

	printf("\nMapped List:\n");
	ft_lstiter(mapped_lst, print_node);

	while (lst)
	{
		t_list *temp = lst;
		lst = lst->next;
		free(temp);
	}

	while (mapped_lst)
	{
		t_list *temp = mapped_lst;
		mapped_lst = mapped_lst->next;
		free(temp);
	}

	return (0);
}
*/