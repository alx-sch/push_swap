/*
To handle the reading of binary data in a more controlled way, ft_isbinary()
checks if the 'stash' contains non-printable characters and NULL terminators not
followed by another NULL terminator, which indicates an end-of-file (EOF).
If the binary data check was successful (i.e., if non-printable characters or a
single NULL terminator was found without an EOF indication), '1' is returned,
otherwise '0'.
*/

#include "libft.h"

int	ft_isbinary(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		if (stash[i] == '\0' || stash[i] < 32 || stash[i] > 126)
		{
			if (stash[i] == '\0' && stash[i + 1] == '\0')
				break ;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
