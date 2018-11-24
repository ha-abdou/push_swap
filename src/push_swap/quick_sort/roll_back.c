#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	roll_back(t_bundle *bundle, int *pivots)
{
	t_numlist	*end;

	while ((end = get_segment_b_end(bundle, pivots, bundle->last_b)))
	{
		printf("--->%d\n", end->index);
		debug_bundle(bundle);
		sort_top_list_b(bundle, end);
	}
}
