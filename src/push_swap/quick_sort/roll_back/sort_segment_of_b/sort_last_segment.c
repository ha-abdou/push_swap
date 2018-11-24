#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
/*
int		*roll_last_segment(t_bundle *bundle, t_numlist *end)
{
	//get pivots
	//push first half
	//for all pivot
	//		pa if 
	int			*sub_pivots;
	int			i;
	int			t;
	int			tmp_end_1;
	//get pivots

	debug_bundle(bundle);
	sub_pivots = get_pivots(bundle->list_a->index - 1, 1);
	printf("roll last segment: %d, %d\n", bundle->list_a->index - 1, 1);
	tmp_end_1 = bundle->list_a->index - 1;
	print_pivots(sub_pivots, "sub_pivots\n");
	
	//push first half
	i = 0;
	while (bundle->list_b->index != end->index)
	{
		if (bundle->list_b->index > sub_pivots[i])
			pa(bundle, 1);
		else
			rb(bundle, 1);
	}
	if (bundle->list_b->index > sub_pivots[i])
		pa(bundle, 1);
	i++;
	while (sub_pivots[i])
	{
		t = 0;

		while (bundle->list_a->index != tmp_end_1)
		{
			if (bundle->list_a->index < sub_pivots[i])
				pb(bundle, 1);
			else
			{
				ra(bundle, 1);
				t++;
			}
		}
		if (bundle->list_a->index < sub_pivots[i])
			pb(bundle, 1);
		i++;
		if (!sub_pivots[i])
			break ;

		while (bundle->list_b->index != end->index)
		{
			if (bundle->list_b->index > sub_pivots[i])
				pa(bundle, 1);
			else
				rb(bundle, 1);
		}
		if (bundle->list_b->index > sub_pivots[i])
			pa(bundle, 1);

		ft_putstr("for all pivorts\n");
		debug_bundle(bundle);
		throw(0,0);
	}
	debug_bundle(bundle);
	throw(0,0);
	return (sub_pivots);
}

void	roll_back_segment(t_bundle *bundle, int *sub_pivots)
{
	//for all subpivot apllay  sort_segment_debug(bun, pivot[i]);
	t_numlist	*end;

	ft_putstr("roll back segment:\n");
	while ((end = get_segment_b_end(bundle, sub_pivots, bundle->last_b)))
	{
		debug_bundle(bundle);
		sort_segment_debug(bundle, end);
		debug_bundle(bundle);
	}	
}

void	sort_last_segment_debug(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	t_numlist	*tmp;

	tmp = bundle->list_a;
	sub_pivots = roll_last_segment(bundle, end);
	sort_top_list_a(bundle, tmp);
	roll_back_segment(bundle, sub_pivots);
	print_pivots(sub_pivots, "sup pivots last segment\n");
	debug_bundle(bundle);
//	throw(0,0);

}*/