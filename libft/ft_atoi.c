/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:33:52 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:18:30 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The atoi() function transforms a string into its corresponding integer
representation.
The string provided as a parameter may start with any number of leading
whitespaces, as determined by isspace(3). Following these whitespaces, there
may be an optional single '+' or '-' sign. The conversion continues until the
first character that is not a valid digit in the specified base is encountered.
For our purposes, where we only need to handle base 10, valid digits: 0-9.
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = sign * -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	int_num[100];
	int		lib_res;
	int		my_res;

	char test_cases[][100] =
	{
		"123",
		"-123",
		"	123",
		"123	",
		"   123   ",
		"   -123   ",
		"   +123   ",
		"",
		"abc-123",
		"  123abc",
		"2147483647",
		"-2147483648",
		"2147483648",
		"-2147483649"
	};

	printf("=======================\n");
	printf("== TESTING FT_ATOI() ==\n");
	printf("=======================\n\n");

	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i)
	{
		strcpy(int_num, test_cases[i]);
		lib_res = atoi(int_num);
		my_res = ft_atoi(int_num);

		printf("Testing: '%s'\n", int_num);
		printf("Lib atoi(): %d\n", lib_res);
		printf("My ft_atoi(): %d\n", my_res);

		if (lib_res == my_res)
			printf("OK!\n\n");
		else
			printf("ERROR!\n\n");
	}
	return (0);
}
*/
