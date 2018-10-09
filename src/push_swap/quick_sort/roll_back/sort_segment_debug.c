#include "libft.h"
#include "push_swap.h"
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

int		*roll_last_segment(t_bundle *bundle, t_numlist *end)
{
	//get pivots
	//push first half
	//for all pivot
	//		pa if 
	int			*sub_pivots;
	int			i;
	//get pivots

	sub_pivots = get_pivots(bundle->list_a->index - 1, 0);
	printf("roll last segment: %d, %d\n", bundle->list_a->index - 1, 0);
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
		ft_putstr("for all pivorts\n");
		debug_bundle(bundle);
		throw(0,0);
	}
	debug_bundle(bundle);
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
	int			i;
	t_numlist	*tmp;


	ft_putstr("sort last segment:\n");

	tmp = bundle->list_a;
	sub_pivots = roll_last_segment(bundle, end);
	sort_top_list_a(bundle, tmp);
	roll_back_segment(bundle, sub_pivots);
	print_pivots(sub_pivots, "sup pivots last segment\n");
	debug_bundle(bundle);
//	throw(0,0);

}

void	sort_big_segment_debug(t_bundle *bundle, t_numlist *end)
{
	ft_putstr("sort big segment:\n");
	//roll segment
	//roll back segment
	throw(0,0);
}

void	sort_segment_debug(t_bundle *bundle, t_numlist *end)
{
	//todo while in place of if
	if (bundle->list_a->index == bundle->list_b->index + 1)
		pa(bundle, 1);
	if (!end->next && bundle->list_a->index > 4)
		sort_last_segment_debug(bundle, end);
	else if (bundle->list_a->index - 1 - end->index <= 3)
		sort_small_segment_debug(bundle, end);
	else
		sort_big_segment_debug(bundle, end);
}
