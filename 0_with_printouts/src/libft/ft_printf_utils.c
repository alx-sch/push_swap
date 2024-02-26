/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:43:10 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/27 17:13:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

//	%c: Prints a single character and returns printout length.
int	print_count_char(char _char)
{
	ft_putchar_fd(_char, 1);
	return (1);
}

//	%s: Prints a string.
//	Returns printout length or '(null)' if string is NULL.
int	print_count_string(char *str)
{
	if (!str)
		return (print_count_string("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

//	%u: Prints an unsigned decimal (base 10) number and returns printout length.
//	As the parameter type is'unsigned int', the need for a neg. value check
//	is eliminated -> used in print_count_number().
int	print_count_unsigned(unsigned int nbr)
{
	int	nbr_length;

	nbr_length = 0;
	if (nbr < 10)
		nbr_length = print_count_char(nbr + '0');
	else
	{
		nbr_length += print_count_unsigned(nbr / 10);
		nbr_length += print_count_unsigned(nbr % 10);
	}
	return (nbr_length);
}

//	%d: Prints a decimal (base 10) number and returns printout length.
//	%i: Prints an integer in base 10 (so same as above) and returns po length.
//	Adjustment of ft_putnbr_fd() from libft to include return of length.
int	print_count_number(int nbr)
{
	int	nbr_length;

	nbr_length = 0;
	if (nbr == -2147483648)
	{
		nbr_length += print_count_char('-') + print_count_char('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr_length = print_count_char('-');
		nbr *= -1;
	}
	return (nbr_length + print_count_unsigned((unsigned int)nbr));
}

//	%x: Prints a number in hexadecimal (base 16) lowercase format.
//	%X: Prints a number in hexadecimal (base 16) uppercase format.
//	Also returns printout length.
int	print_count_hex(uintptr_t nbr, char format)
{
	if (nbr >= 16)
	{
		return (print_count_hex(nbr / 16, format)
			+ print_count_hex(nbr % 16, format));
	}
	else
	{
		if (nbr <= 9)
			return (print_count_char(nbr + '0'));
		else if (format == 'x')
			return (print_count_char(nbr - 10 + 'a'));
		else if (format == 'X')
			return (print_count_char(nbr - 10 + 'A'));
	}
	return (0);
}
