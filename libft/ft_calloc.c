/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:48:45 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/27 19:59:27 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
calloc() functions similarly to malloc(); however, it distinguishes itself by
initializing all allocated memory bytes to zero. This stands in contrast
to malloc(), which leaves the memory content as it was, containing potential
random or "gibberish" values from previous data stored in that memory location.

calloc() function is specified to always return a valid pointer that can be
safely used to access elements (even when the number of elements is 0).
It essentially provides a valid, empty block of memory.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 0)
	{
		if (SIZE_MAX / nmemb < size)
			return (NULL);
	}
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>

void	*test_calloc(size_t num_el, size_t el_size, const char *el_type)
{
	void	*arr_lib = calloc(num_el, el_size);
	void	*arr_my = ft_calloc(num_el, el_size);

	if (arr_lib == NULL)
		printf("Lib calloc():\nNo memory allocation.\n");
	else
	{
		printf("Lib calloc():\nAllocated memory block: '");
		for (size_t i = 0; i < num_el; ++i)
		{
			if (strcmp(el_type, "char") == 0)
				printf("%c ", ((char *)arr_lib)[i]);
			else if (strcmp(el_type, "int") == 0)
				printf("%d ", ((int *)arr_lib)[i]);
			// Add more cases for other types as needed
		}
		printf("'\n");
	}

	if (arr_my == NULL)
		printf("My ft_calloc():\nNo memory allocation.\n");

	else
	{
		printf("My ft_calloc():\nAllocated memory block: '");
		for (size_t i = 0; i < num_el; ++i)
		{
			if (strcmp(el_type, "char") == 0)
				printf("%c ", ((char *)arr_lib)[i]);
			else if (strcmp(el_type, "int") == 0)
				printf("%d ", ((int *)arr_lib)[i]);
			// Add more cases for other types as needed
		}
		printf("'\n");
	}

	if (arr_lib != NULL && arr_my != NULL)
	{
		if (memcmp(arr_lib, arr_my, num_el * el_size) == 0)
			printf("--> OK!\n\n");
		else
			printf("--> ERROR!\n\n");
	}
	else
		printf("--> OK! (no memory allocation)\n\n");

	if (arr_lib != NULL)
		free(arr_lib);
	if (arr_my != NULL)
		free(arr_my);

	return (NULL);
}

int	main(void)
{
	printf("=========================\n");
	printf("== TESTING FT_CALLOC() ==\n");
	printf("=========================\n\n");

	size_t number_m_blocks = 10;

	printf("NOTE: Printing 'space' between elements for visualization.\n\n");

	// Testing integers
	printf("Allocating memory for %zu int elements.\n", number_m_blocks);
	test_calloc(number_m_blocks, sizeof(int), "int");

	// Testing integers
	printf("Allocating memory for %zu char elements.\n", number_m_blocks);
	test_calloc(number_m_blocks, sizeof(char), "char");

	printf("*****\n");
	printf("NOTE: For the next two examples, the output for calloc()\n"
		"and ft_calloc() can differ, as both, 1) a return of NULL,\n"
		"or 2) a valid pointer to 'zero-sized' block that can be\n"
		"passed to free() are valid.\n"
		"The memory comparison should be 'OK!', however.\n");
	printf("*****\n\n");

	// Testing zero elements
	printf("Allocating memory for 0 char elements.\n");
	test_calloc(0, sizeof(char), "char");

	// Testing zero size
	printf("Allocating memory for 10 char elements with 0 size.\n");
	test_calloc(number_m_blocks, 0, "char");

	// Testing overflow prevention
	number_m_blocks = SIZE_MAX;
	size_t size = SIZE_MAX;

	printf("Testing size_t overflow handling.\n");
	test_calloc(number_m_blocks, size, "char");

	return (0);
}
*/
