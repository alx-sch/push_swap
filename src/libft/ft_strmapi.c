/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:37:36 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/27 17:24:22 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of ft_strmapi() is to apply a given function f to each character of
the input string s. The function f takes two arguments: the index of the
character in the string and the character itself. The result of applying f to
each character is used to create a new string, where each character is determined
by the corresponding application of f.

In the testing program, a wrapper function is employed to use existing functions
with more ease.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <stdio.h>

char	ft_wrapper(unsigned int index, char c)
{
	(void)index;
	return (ft_toupper(c));
}

int	main(void)
{
	char	test_str[] = "A test string to be modified by ft_strmapi()";

	printf("String before ft_strmapi(): '%s'\n", test_str);
	printf("String after ft_strmapi(): '%s'\n",
		ft_strmapi(test_str, ft_wrapper));

	return (0);
}
*/
