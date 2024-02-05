/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:27 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:22:11 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of this function is to write 'len' bytes of the value 'c' to a
string. The return value is the first parameter of the function, which is the
void pointer to the string.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	char_c;

	ptr = (unsigned char *)s;
	char_c = (unsigned char) c;
	while (n > 0)
	{
		*ptr = char_c;
		ptr++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char chars[10] = "ABCDEFGHIJ";
	char my_chars[10] = "ABCDEFGHIJ";
	memset(chars + 5, 'X', 4 * sizeof(char));
	ft_memset(my_chars + 5, '9', 4 * sizeof(char));
	printf("== TEST: Set a certain block of memory to specific char value ==\n");

	printf("memset():\n");
	int i = 0;
	while (i < 10)
	{
		printf("%c ", chars[i]);
		i++;
	}
	printf("\nft_memset():\n");
	i = 0;
	while (i < 10)
	{
		printf("%c ", my_chars[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/