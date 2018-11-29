#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void		f_1(t_bundle *bundle, int pivot)
{
	if (bundle->list_b->index > pivot)
		pa(bundle, 1);
	else if (bundle->list_b->index == pivot)
	{
		pa(bundle, 1);
		ra(bundle, 1);
	}
	else
		rb(bundle, 1);
}

static void		push_first_half(t_bundle *bundle, int pivot, int end_index)
{
	int		tmp;

	tmp = bundle->last_b->index;
	while (bundle->list_b->index != end_index)
		f_1(bundle, pivot);
	if (bundle->list_b->index > pivot)
		pa(bundle, 1);
	if (bundle->list_b->index == pivot)
	{
		pa(bundle, 1);
		ra(bundle, 1);
	}
	if (end_index != tmp)
		while (bundle->last_b->index != tmp)
			rrb(bundle, 1);
	rra(bundle, 1);	
	pb(bundle, 1);
}

static void		f_2(t_bundle *bundle, int pivot, int stop_2)
{
	while (bundle->last_a->index != stop_2)
	{
		rra(bundle, 1);
		if (bundle->list_a->index < pivot)
			pb(bundle, 1);
		if (bundle->list_a->index == pivot)
		{
			pb(bundle, 1);
			rb(bundle, 1);
		}
	}
	rrb(bundle, 1);
}

static void		push_second_half(t_bundle *bundle, int *pivots,int s1, int s2)
{
	int		i;

	i = 1;
	while (pivots[i])
	{
		while (bundle->list_a->index != s1)
		{
			if (bundle->list_a->index < pivots[i])
				pb(bundle, 1);
			else if (bundle->list_a->index == pivots[i])
			{
				pb(bundle, 1);
				rb(bundle, 1);
			}
			else
				ra(bundle, 1);
		}
		rrb(bundle, 1);
		i++;
		if (!pivots[i])
			break ;
		f_2(bundle, pivots[i], s2);
		i++;
	}
}

int			*roll_segment(t_bundle *bundle, int end_index, int min)
{
	int		*pivots;
	int		stop_1;
	int		stop_2;

	pivots = get_pivots(bundle->list_a->index - min, min - 1);
	stop_1 = bundle->list_a->index;
	stop_2 = bundle->last_a->index;
	push_first_half(bundle, pivots[0], end_index);
	push_second_half(bundle, pivots, stop_1, stop_2);
	while (bundle->last_a->index != stop_2)
		rra(bundle, 1);
	return (pivots);
}
