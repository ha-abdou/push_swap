#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
/**
* sort top of list_a
* case 1: 1 elm to sort
* case 2: 2 elm to sort swap_a if neaded
* case 3: 3 elm to sort (todo better way)
*/

static void sort_3(t_bundle *bundle, t_numlist *end)
{
	int		is_ra;

	is_ra = 0;
	if (bundle->list_a->index < bundle->list_a->next->index && bundle->list_a->index < end->index)
	{
		is_ra = 1;
		ra(bundle, 1);
	}
	else
		pb(bundle, 1);
	if (bundle->list_a->index < bundle->list_a->next->index && !is_ra)
		ra(bundle, (is_ra = 1));
	else
		pb(bundle, 1);
	if (is_ra)
		pb(bundle, 1);
	else
		ra(bundle, 1);
	if (bundle->list_b->index < bundle->list_b->next->index)
		sb(bundle, 1);
	pa(bundle, 1);
	pa(bundle, 1);
	rra(bundle, 1);
}


void	sort_top_list_a(t_bundle *bundle, t_numlist *end)
{
	if (bundle->list_a->index == end->index || bundle->list_a->next->index == end->index)
		return ;
	if (bundle->list_a->next->next->index == end->index)
	{
		if (bundle->list_a->index > bundle->list_a->next->index)
			sa(bundle, 1);
		return ;
	}
	if (bundle->list_a->next->next->next->index == end->index)
		sort_3(bundle, bundle->list_a->next->next);
}
/*
void	sort_top_list_a(t_bundle *bundle, t_numlist *end)
{
	if (bundle->list_a->index == end->index)
		return ;
	if (bundle->list_a->next->index == end->index)
	{
		if (bundle->list_a->index > end->index)
			sa(bundle, 1);
		return ;
	}
	if (bundle->list_a->next->next->index == end->index)
		sort_3(bundle, end);
}
*/