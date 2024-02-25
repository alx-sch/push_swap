/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:44:09 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/27 17:55:46 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Same as ft_putstr_fd() but also prints a newline after the string.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int	main(void)
{
	char	test_str[] = "Print me!";

	ft_putendl_fd(test_str, 1);
	return (0);
}
*/
