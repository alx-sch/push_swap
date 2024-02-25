/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:06:52 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:19:27 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

void	test_isalnum(char ch)
{
	int result_lib = ft_isalnum(ch);
	int result_my = ft_isalnum(ch);

	printf("Character: %c\n", ch);
	printf("Lib isalnum(): %d\n", result_lib);
	printf("My ft_isalnum(): %d\n", result_my);

	if (result_lib == result_my)
		printf("--> OK!\n");
	else
		printf("--> ERROR!\n");
	printf("\n");
}

int	main(void)
{
	printf("==========================\n");
	printf("== TESTING FT_ISALNUM() ==\n");
	printf("==========================\n\n");

	printf("*****\n");
	printf("NOTE: Interestingly, the library function does \n"
		"not necessarily return '1', but rather any nonzero value.\n");
	printf("*****\n\n");

	test_isalnum('a'); // Alphanumeric, should return 1 (true)
	test_isalnum('5'); // Alphanumeric, should return 1 (true)
	test_isalnum('$'); // Not alphanumeric, should return 0 (false)

	return (0);
}
*/
