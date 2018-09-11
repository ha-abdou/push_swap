#include "libft.h"
#include "push_swap.h"

void	ss(t_bundle *bundle, int save)
{
	sa(bundle, 0);
	sb(bundle, 0);
	if (save)
	{
		bundle->operations[bundle->operations_length] = 11;
		bundle->operations_length++;
	}
}
