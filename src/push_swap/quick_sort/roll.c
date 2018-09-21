#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		*roll(t_bundle *bundle)
{
	int			*pivots;
	int			last_index;
	int			i;
	//get pivots
	pivots = get_pivots(bundle->list_a_length, 0);
	i = 0;
	while (pivots[i])
	{
		printf(RED "pivot: %s%d%s\n" , GRN, pivots[i], RESET);
		last_index = bundle->last_a->index;

		//check for first elm
//		printf(RED "-->last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
		handel_first(bundle, pivots[i]);
//		printf(RED "last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
		//check for all
//		debug_bundle(bundle);
		while (last_index != bundle->list_a->index)
		{
			handel_first(bundle, pivots[i]);
//			printf(RED "last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
//			debug_bundle(bundle);
		}
		handel_first(bundle, pivots[i]);
		//rotate pivots to to of list_b
		rrb(bundle, 1);
		i++;
	}
	sort_top_list_a(bundle, bundle->last_a);
	return (pivots);
}