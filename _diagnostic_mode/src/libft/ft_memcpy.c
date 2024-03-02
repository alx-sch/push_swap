/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:33:40 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:21:52 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcpy function efficiently copies up to 'n' bytes from the source (src) to
the destination (dst). This function operates similarly to strcpy, yet
distinguishes itself by accepting void * as parameters. Consequently, memcpy()
accommodates copying of data pointed to by any type of pointer, offering a
versatile and adaptable copying mechanism.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	const char	*char_src;

	char_dest = (char *) dest;
	char_src = (const char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main (void)
{
	// Testing with strings (works with null)
	char src[] = "Copy this!";
	char dest[100] = "destination";

	printf("Before ft_memcpy():\n");
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	ft_memcpy(dest, src, sizeof(src));
	printf("After ft_memcpy():\n");
	printf("src: %s\n", src);
	printf("dest: %s\n\n", dest);

	//Testing to see if pointer address in dest_ptr and dest are the same
	printf("Check if pointer address stays the same:\n");
	char *dest_after = ft_memcpy(dest, src, sizeof(src));
	printf("dest (before): %p\n", dest);
	printf("dest (after) %p\n\n", dest_after);


	// Testing with arrays
	int src_array [5] = {1, 2, 3, 4, 5};
	int dst_array[5];

	ft_memset(dst_array, 0, sizeof(dst_array));

	printf("Testing with arrays:\n");
	printf("Before ft_memcpy():\n");
	printf("src_array: ");

	int 	i;

	i = 0;
	while (i < 5)
	{
		printf("%d ", src_array[i]);
		i++;
	}
	printf("\n");

	printf("dst_array: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", dst_array[i]);
		i++;
	}
	printf("\n");

	ft_memcpy(dst_array, src_array, sizeof(src_array));
	printf("Before ft_memcpy():\n");
	printf("src_array: ");

	i = 0;
	while (i < 5)
	{
		printf("%d ", src_array[i]);
		i++;
	}
	printf("\n");

	printf("dst_array: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", dst_array[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/
