/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:44:06 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:24:28 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr() function performs a similar task as strchr(), but instead of
locating the first occurrence of the character c from the beginning of the
string, strrchr() identifies the last occurrence of c by searching from the end
of the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	int		i;

	char_c = (char) c;
	i = ft_strlen(s);
	s += i;
	while (i >= 0)
	{
		if (*s == char_c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "Hello World, Walter!";
	char	*result;
	int		c = 287; // 87 == 'W'

	result = ft_strrchr(s, c);

	if (result == NULL)
		printf("'%c' not found in '%s'.\n", c, s);
	else
		printf("Last occurence of '%c' found in '%s' at position %ld.\n",
		c, s, result - s);

	return (0);
}
*/