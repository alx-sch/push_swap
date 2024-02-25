/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:27:15 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/23 14:47:14 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memmove() function performs the same task as memcpy(), but with a crucial
distinction – it executes the copy operation in a non-destructive manner. Unlike
memcpy(), memmove() is designed to handle overlapping memory regions, ensuring
that it does not inadvertently overwrite part or the entirety of the string
during the copying process.

The significance of this non-destructive behavior becomes apparent when the
source (src) and destination (dst) strings overlap in memory. Particularly
noteworthy is the scenario where src precedes dst, allowing for changes in src
while copying.
To address this, the condition (size_t)dest - (size_t)src < n becomes relevant,
ensuring the proper handling of cases where src precedes dst.
This condition evaluates to true only when src is positioned before dst,
as a 'negative' (size_t)dest - (size_t)src is non-existent -> looping to SIZE_MAX
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

void printArray(const char *label, const char *arr, size_t size) {
	printf("%s", label);
	for (size_t i = 0; i < size; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

int main()
{
	char original[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	char *src = original;
	char *dest1 = original + 2;

	size_t n = 3;

	printf("== Before ft_memmove() ==\n");
	printArray("Memory block: ", original, 6);
	printArray("Src: ", src, 4);
	printArray("Dst: ", dest1, 4);

	printf("\nBytes to be moved from src to dst: %zu\n", n);
	ft_memmove(dest1, src, n);
	printf("\n== After ft_memmove() ==\n");
	printArray("Memory block: ", original, 6);
	printArray("Src: ", src, 4);
	printArray("Dst: ", dest1, 4);

	return (0);
}
*/
