#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	sort_top_list_b(t_bundle *bundle, t_numlist *end)
{
	int			i;
	t_numlist	*top_a;

	//case of segment < 3 elm
	if (bundle->list_b->index - end->index <= 4)
	{
		i = 0;
		pa(bundle, 1);
		top_a = bundle->list_a;
		//
		while (bundle->list_b->index != end->index)
		{
			pa(bundle, 1);
			if (top_a->index + 1 != bundle->list_a->index )
			{
				i++;
				ra(bundle, 1);	
			}
		}
		while (i)
		{
			i--;
			rra(bundle, 1);
		}
		if (bundle->list_a->index > bundle->list_a->next->index)
			sa(bundle, 1);
	}//case of big segment
	else
	{
		printf("roll_back:\n");
		debug_bundle(bundle);
		printf("++++++++++++++++todo: %d, %d\n", end->index, bundle->list_b->index);
		throw(0, 0);
	}
}
