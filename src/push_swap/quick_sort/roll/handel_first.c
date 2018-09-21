#include "libft.h"
#include "push_swap.h"

void	handel_first(t_bundle *bundle, int pivot)
{
	if (bundle->list_a->index > pivot)
		ra(bundle, 1);
	else if (bundle->list_a->index == pivot)
	{
		pb(bundle, 1);
		rb(bundle, 1);
	}
	else
		pb(bundle, 1);
}