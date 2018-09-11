#include "libft.h"
#include "push_swap.h"

void	rrr(t_bundle *bundle, int save)
{
	rra(bundle, 0);
	rrb(bundle, 0);
	if (save)
	{
		bundle->operations[bundle->operations_length] = 8;
		bundle->operations_length++;
	}
}
