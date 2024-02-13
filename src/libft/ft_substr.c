/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:47:01 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 15:28:14 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_substr() returns a substring of the string s passed as parameter.

The ft_substr function takes a string s, a starting index start, and a length
len as parameters. It first checks if the input string is NULL, and if so, it
returns NULL to indicate an invalid input. It then verifies if the starting
index is beyond the length of the string; if true, it returns an empty string.
The function calculates the remaining length of the string after the specified
start index and adjusts the length parameter if it exceeds the remaining length.
Finally, the function allocates memory for a substring, copies the appropriate
portion from the input string, and returns the newly allocated substring.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	remaining_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	remaining_len = ft_strlen(s + start);
	if (len > remaining_len)
		len = remaining_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len +1);
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	unsigned int	start;
	size_t			len;
	char *src_ptr = "We are supercalifragilisticexpialidocious!";

	printf("Source: '%s'\n\n",src_ptr);

	start = 7;
	len = 9;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 7;
	len = 99;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 99;
	len = 7;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 7;
	len = 9;
	src_ptr = NULL;
	printf("Source: '%s'\n",src_ptr);
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n",ft_substr(src_ptr, start, len));

	return (0);
}
*/
