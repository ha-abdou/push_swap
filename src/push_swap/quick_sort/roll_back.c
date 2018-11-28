#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	roll_back(t_bundle *bundle, int *pivots)
{
	t_numlist	*end;
	int			min_index;
	int			i;

	i = 0;
	while (pivots[i])
		i++;
	i--;
	while (i >= 0)
	{

		min_index = 1;
		if (i > 0)
			min_index = pivots[i - 1];
		end = bundle->list_b;
		while (end->next->index != min_index)
			end = end->next;
		pa(bundle, 1);
		if (min_index == 1)
			end = bundle->last_b;
//		printf("roll back: %d, %d *******************************************\n", bundle->list_b->index, end->index);
//		debug_bundle_pivots(bundle, pivots);
		sort_segment(bundle, end);
		i--;
//		debug_bundle_pivots(bundle, pivots);
//		printf("end roll *******************************************\n");

	}
}
