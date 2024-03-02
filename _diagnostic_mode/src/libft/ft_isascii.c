/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:05 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:19:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

void	test_isascii(int ch)
{
	int result_std = isascii(ch);
	int result_ft = ft_isascii(ch);

	printf("Character: %c\n", ch);
	printf("Lib isascii(): %d\n", result_std != 0);
	printf("My ft_isascii(): %d\n", result_ft != 0);

	if ((result_std == 0 && result_ft == 0)
		|| (result_std > 0 && result_ft > 0))
		printf("--> OK!\n\n");
	else
		printf("--> ERROR!\n\n");
}

int	main(void)
{
	printf("==========================\n");
	printf("== TESTING FT_ISASCII() ==\n");
	printf("===========================\n\n");

	printf("*****\n");
	printf("NOTE: Interestingly, the library function does \n"
		"not necessarily return '1', but rather any nonzero value.\n");
	printf("*****\n\n");

	test_isascii('A');
	test_isascii(150); // Not ASCII, should return 0 (false)
	test_isascii('$');

	return (0);
}
*/
