/*
The strdup() function returns a pointer to a newly created string, serving as a
duplicate of the input string 'src'. The memory for this new string is allocated
using malloc().

Upon success, strdup() provides a pointer to the duplicated string. In case of
insufficient available memory, it returns NULL.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new_s)
		return (NULL);
	while (*src)
		new_s[i++] = *src++;
	new_s[i] = '\0';
	return (new_s);
}

/*
# include <stdio.h>

int	main(void)
{
	char *mine;
	char *library;
	char test_string[30] = "Copy Me!";

	mine = ft_strdup(test_string);
	library = strdup(test_string);
	printf("'My' fct: '%s'\nLib fct: '%s'\n", mine, library);
	printf("Bytes in test: %zu\n", sizeof(test_string));
	printf("Bytes in 'my' fct: %zu\n", sizeof(mine));
	printf("Bytes in 'lib' fct': %zu\n", sizeof(library));

	return (0);
}
*/
