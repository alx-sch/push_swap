/*
c: The character to output.
fd: The file descriptor on which to write.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	char	test_str[] = "Print me!";
	char	*ptr = test_str;

	while (*ptr)
	{
		ft_putchar_fd(*ptr, 1);
		ptr++;
	}
	ft_putchar_fd('\n', 1);

	return (0);
}
*/
