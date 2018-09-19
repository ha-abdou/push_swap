#include "libft.h"
#include "push_swap.h"

void	br(t_bundle *bundle, int save)
{
	if (save)
	{
		bundle->operations[bundle->operations_length] = 12;
		bundle->operations_length++;
	}
}
