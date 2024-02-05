/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:21:01 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:24:04 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strncmp() function performs a lexicographic comparison of two strings by
comparing each character based on their ASCII values. It compares a maximum
of n characters in both strings. The result of the comparison depends on the
first difference encountered.
-	If the two strings are identical, the function returns 0, indicating
	no difference.
-	If a difference is found, and the first differing character in the second
	string (s2) is greater than the character at the same position in the first
	string (s1), the result is negative.
-	If the first differing character in s2 is less than the character at the
	same position in s1, the result is positive.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		n;
	char	string1[50];
	char	string2[50];

	n = 9;
	strcpy(string1, "1234567890");
	strcpy(string2, "1234567");

	printf(" \n");
	printf("== TEST ==\nS1: %s\nS2: %s\nn:%d\n", string1, string2, n);
	printf("Result strcmp(): %d\n", strncmp(string1, string2, n));
	printf("Result 'my' ft_strcmp(): %d\n", ft_strncmp(string1, string2, n));

	return (0);
}
*/
