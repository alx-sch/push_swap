/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:12:56 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/22 19:22:06 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

void	test_isprint(char ch)
{
	int	result_std = isprint(ch);
	int	result_ft = ft_isprint(ch);

	printf("Character: %c\n", ch);
	printf("Lib isprint(): %d\n", result_std != 0);
	printf("My ft_isprint(): %d\n", result_ft != 0);

	if ((result_std == 0 && result_ft == 0)
		|| (result_std > 0 && result_ft > 0))
		printf("--> OK!\n\n");
	else
		printf("--> ERROR!\n\n");
}

int	main(void)
{
	printf("==========================\n");
	printf("== TESTING FT_ISPRINT() ==\n");
	printf("==========================\n\n");

	test_isprint('A');
	test_isprint('\t'); // Not printable, should return 0 (false)
	test_isprint('$');

	return (0);
}
*/
