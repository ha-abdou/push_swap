#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
//if is small
//if is big
//if is last

//todo less moves

void	sort_small_segment_debug(t_bundle *bundle, t_numlist *end)
{
	int		i;

	printf("sort small segment: %d, %d\n", bundle->list_b->index, end->index);
	debug_bundle(bundle);
	i = 0;
	while (bundle->list_b->index != end->index)
	{
		pa(bundle, 1);
		if (bundle->list_a->index + 1 != bundle->list_a->next->index)
		{
			i++;
			ra(bundle, 1);	
		}
	}
	if (bundle->list_b->index + 1 == bundle->list_a->index)
		pa(bundle, 1);
	while (i)
	{
		i--;
		rra(bundle, 1);
	}
	if (bundle->list_b && bundle->list_b->index == end->index)
		pa(bundle, 1);
	if (bundle->list_a->index > bundle->list_a->next->index)
		sa(bundle, 1);
	debug_bundle(bundle);
}
