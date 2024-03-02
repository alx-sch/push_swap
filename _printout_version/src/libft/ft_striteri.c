/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:39:13 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/27 17:24:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Works like ft_strmapi() with the difference that ft_striteri() applies function
f directly on the original string.
Passing the address (a pointer) as to modify the actual memory location of the
index / char.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !(*s) || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	ft_wrapper(unsigned int index, char *c)
{
	(void)index;
	*c = (ft_toupper(*c));
}


int	main(void)
{
	char	test_str[] = "A test string to be modified by ft_strmapi()";

	printf("String before ft_strmapi(): '%s'\n", test_str);
	ft_striteri(test_str, ft_wrapper);
	printf("String after ft_strmapi(): '%s'\n", test_str);

	return (0);
}
*/
