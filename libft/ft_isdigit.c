/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:15 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:20:31 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

void	test_isdigit(char ch)
{
	int	result_std = isdigit(ch);
	int	result_ft = ft_isdigit(ch);

	printf("Character: %c\n", ch);
	printf("Lib isdigit(): %d\n", result_std != 0);
	printf("My ft_isdigit(): %d\n", result_ft != 0);

	if ((result_std == 0 && result_ft == 0)
		|| (result_std > 0 && result_ft > 0))
		printf("--> OK!\n\n");
	else
		printf("--> ERROR!\n\n");
}

int	main(void)
{
	printf("==========================\n");
	printf("== TESTING FT_ISDIGIT() ==\n");
	printf("==========================\n\n");

	test_isdigit('5');
	test_isdigit('A');
	test_isdigit('$');

	return (0);
}
*/
