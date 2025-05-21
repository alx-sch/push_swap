/*
Computes the length of the null-terminated string str.
The function returns the number of characters in the string str, excluding
the NUL terminator ('\0').
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("length of 'bananapie!': %zu\n", ft_strlen("bananapie!"));

	return (0);
}
*/