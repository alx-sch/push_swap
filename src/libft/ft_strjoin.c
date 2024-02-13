/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:24 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:23:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function operates similarly to ft_strlcat(), but instead of requiring a
pre-allocated destination string as a parameter, it accepts two strings, and
ft_strjoin() autonomously allocates the necessary memory for both strings along
with the null-terminating character. The first string, s1, becomes the initial
segment of the resulting string, while the second string, s2, follows it in
the concatenated result.

It first checks if either of the input strings is NULL, and if so, it returns
NULL to indicate an invalid operation. The lengths of the input strings are
calculated using ft_strlen. The resulting concatenated string is allocated
enough memory, and the content of s1 and s2 are copied to this memory using
ft_memcpy(). The newly created string is then returned.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len1 + len2 +1));
	if (!strjoin)
		return (NULL);
	ft_memcpy(strjoin, s1, len1);
	ft_memcpy(strjoin + len1, s2, len2 + 1);
	return (strjoin);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strjoin("Hello", " World!"));

	return (0);
}
*/
