/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:44:08 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:22:31 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strchr() function is designed to locate a specific character within a string.
Upon finding the character, it returns a pointer pointing to the first occurrence
of that particular character. In the event that no instance of the character is
found, the function returns NULL.
It's important to note that if the character being searched for is '\0',
the function still needs to return a pointer pointing to this character.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	char_c;

	char_c = (char)c;
	while (*s != '\0')
	{
		if (*s == char_c)
			return ((char *)s);
		s++;
	}
	if (*s == char_c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "Hello World, Walter!";
	char	*result;
	int		c = 87; // 87 == 'W'

	result = ft_strchr(s, c);

	if (result == NULL)
		printf("'%c' not found in '%s'.\n", c, s);
	else
		printf("First occurence of '%c' found in '%s' at position %ld.\n",
		c, s, result - s);

	return (0);
}
*/
