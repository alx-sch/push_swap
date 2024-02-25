/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:16:30 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:23:32 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function serves a straightforward purpose – concatenating two strings,
always ensuring the resulting string is NULL-terminated. If the provided 'size'
is sufficiently large to accommodate the concatenation without truncation,
strlcat() seamlessly combines the two strings, akin to strcat().

However, when the 'size' is insufficient, strlcat() concatenates
'size - strlen(dst) - 1' characters, followed by adding the NUL-terminating
character. Crucially, regardless of whether truncation occurs, the function
consistently returns the length of the string it attempted to create.
This length comprises the original lengths of both 'dst' and 'src'.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	j = len_dst;
	if (len_dst < size)
	{
		while (src[i] && (len_dst + i) < (size - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	else
		len_dst = size;
	return (len_dst + len_src);
}

/*
#define BUFFER_SIZE 33
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dst[BUFFER_SIZE] = "I am destination!";
	char src[] = "I am source!123456";
	size_t max_n = BUFFER_SIZE - ft_strlen(dst) - 1;

	printf("src string before ft_strlcat(): %s\n", dst);
	printf("dst string before ft_strlcat(): %s\n", src);
	printf("Size of dest buffer: %zu\n",sizeof(dst));
	printf("Length of dst string: %zu\n",ft_strlen(dst));
	printf("Length of src string to be appended to dst string: %zu\n",
		ft_strlen(src));
	printf("Max. number of chars that can be appended to dst: %zu\n", max_n);

	size_t result = ft_strlcat(dst, src, sizeof(dst));

	printf("Return of ft_strlcat() (expected len of string "
		"to be created): %zu\n", result);
	printf("dst string after ft_strlcat(): %s\n", dst);

	return (0);
}
*/