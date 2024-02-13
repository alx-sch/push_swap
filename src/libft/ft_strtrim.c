/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:33:31 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:14:17 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_strtrim() function trims the input string s1 by removing the characters
specified in the set string from both the beginning and the end of s1.
It retains characters from the set that appear in the middle of s1 and focuses
solely on trimming leading and trailing occurrences of characters found in the
set string.

 If s1 is NULL, the function returns NULL. If set is NULL, it duplicates the
 entire string s1. The function then determines the start and end positions
 by skipping characters from the beginning and end of s1 that match those
 in the set string. Finally, it returns a newly allocated substring containing
 the trimmed portion of the original string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtim;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	strtim = ft_substr(s1, start, end - start + 1);
	return (strtim);
}

/*
#include <stdio.h>

int	main(void)
{
	char string[] = "ab+abaaaForty-two!b+baaabbab";
	char set [] = "a+b";

	printf("String: '%s'\n", string);
	printf("Chars to trim: '%s'\n", set);
	printf("Trimmed string: '%s'\n", ft_strtrim(string, set));

	return (0);
}
*/
