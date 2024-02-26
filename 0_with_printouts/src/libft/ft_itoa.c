/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:29:56 by aschenk           #+#    #+#             */
/*   Updated: 2023/12/05 11:39:49 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_itoa function performs the inverse operation of ft_atoi, converting a
numerical value into its corresponding string representation.

ft_count_digits():
Counts number of digits (incl. '-') in an int. The purpose is to determine the
number of characters needed to represent the integer as a string.

ft_itoa():
Allocates memory for the string based on the count of digits plus one additional
char for '\0'. Converts 'int' to 'char' digit by digit from right to left and
fills the string accordingly.
Handles special cases "INT_MIN" (as (INT_MIN *= -1) > INT_MAX) and '0' by
directly creating the string via ft_strdup().
*/

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = ft_count_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));

	return (0);
}
*/
