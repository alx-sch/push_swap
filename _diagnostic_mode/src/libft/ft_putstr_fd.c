/*
s: The string to output.
fd: The file descriptor on which to write.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		ft_putchar_fd(*ptr, fd);
		ptr++;
	}
}

/*
int	main(void)
{
	char	test_str[] = "Print me!";

	ft_putstr_fd(test_str, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
