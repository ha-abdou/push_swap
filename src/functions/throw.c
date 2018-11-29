#include <stdlib.h>
#include "libft.h"
#include <errno.h>

void	throw(int code, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 1);
	exit(code);
}