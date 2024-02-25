/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:37 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:19:46 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

void test_isalpha(char ch)
{
	int result_std = isalpha(ch);
	int result_ft = ft_isalpha(ch);

	printf("Character: %c\n", ch);
	printf("Lib isalpha(): %d\n", result_std);
	printf("My ft_isalpha(): %d\n", result_ft);

	if ((result_std == 0 && result_ft == 0)
		|| (result_std > 0 && result_ft > 0))
		printf("--> OK!\n\n");
	else
		printf("--> ERROR!\n\n");
}

int	main(void)
{
	printf("==========================\n");
	printf("== TESTING FT_ISALPHA() ==\n");
	printf("==========================\n\n");

	printf("*****\n");
	printf("NOTE: Interestingly, the library function does \n"
		"not necessarily return '1', but rather any nonzero value.\n");
	printf("*****\n\n");

	test_isalpha('a');
	test_isalpha('5');
	test_isalpha('$');

	return (0);
}
*/
