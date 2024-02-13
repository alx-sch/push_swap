/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:08 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:23:47 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of this function is straightforward: to copy one string to another
while ensuring the destination string is always NUL-terminated. If you provide
a 'size' large enough to accommodate the entire string without truncation,
strlcpy() behaves like strcpy() and simply copies the entire string.
However, if the provided 'size' is insufficient, it copies 'size' - 1 characters
from the source to the destination, ensuring that the destination
string is NUL-terminated.

An essential feature of strlcpy() is that it always returns the length of
the string it attempted to create. This length corresponds to the length of the
source string, even in cases where the string had to be truncated to ensure
proper NUL-termination.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[] = "HELLOOOO!";
	char str2[] = "len:5";
	size_t size = 6;

	printf("Src string before ft_strlcpy(): '%s'\n", str1);
	printf("Dst string before ft_strlcpy(): '%s'\n", str2);
	printf("Size: %zu\n", size);
	printf("Total length of src string: %zu\n", ft_strlcpy(str2, str1, 6));
	printf("Dst string after ft_strlcpy(): '%s'\n", str2);

	return(0);
}
*/