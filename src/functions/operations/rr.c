#include "libft.h"
#include "push_swap.h"

void	rr(t_bundle *bundle, int save)
{
	rb(bundle, 0);
	ra(bundle, 0);
	if (save)
	{
		bundle->operations[bundle->operations_length] = 5;
		bundle->operations_length++;
	}
}
