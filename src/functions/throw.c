#include <stdlib.h>
#include "libft.h"

void	throw(int code, char *msg)
{
	if (msg)
		ft_putstr(msg);
	exit(code);
}