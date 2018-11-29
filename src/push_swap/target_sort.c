#include "libft.h"
#include "push_swap.h"

void		target_sort(t_bundle *bundle)
{
	int			min;

	min = 1;
	while (!is_numlist_sorted(bundle->list_a))
	{
		while (bundle->list_a->index != min)
			rra(bundle, 1);
		pb(bundle, 1);
		min++;
	}
	while (bundle->list_b)
		pa(bundle, 1);
}
