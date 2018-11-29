#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	handel_first(t_bundle *bundle, int pivot)
{
	if (bundle->list_a->index > pivot)
		ra(bundle, 1);
	else if (bundle->list_a->index == pivot)
	{
		pb(bundle, 1);
		rb(bundle, 1);
	}
	else
		pb(bundle, 1);
}

static int	get_last_index(t_bundle *bundle, int pivot)
{
	t_numlist	*tmp;
	int			last_index;

	tmp = bundle->list_a;
	last_index = tmp->index;
	while (tmp)
	{
		if (tmp->index <= pivot)
			last_index = tmp->index;
		tmp = tmp->next;
	}
	return (last_index);
}

static void	sort_list_a(t_bundle *bundle)
{
	if (bundle->list_a->index == bundle->last_a->index)
		return ;
	if (bundle->list_a->next->index == bundle->last_a->index)
	{
		if (bundle->list_a->index > bundle->last_a->index)
			sa(bundle, 1);
		return ;
	}
	if (bundle->list_a->next->next->index == bundle->last_a->index)
	{
		if (bundle->list_a->index > bundle->list_a->next->index
		&& bundle->list_a->index > bundle->last_a->index)
			ra(bundle, 1);
		else if (bundle->list_a->next->index > bundle->list_a->index
			&& bundle->list_a->next->index > bundle->last_a->index)
		{
			sa(bundle, 1);
			ra(bundle, 1);
		}
		if (bundle->list_a->index > bundle->list_a->next->index)
			sa(bundle, 1);
	}
}

int			*roll(t_bundle *bundle)
{
	int			*pivots;
	int			last_index;
	int			i;

	pivots = get_pivots(bundle->list_a_length, 0);
	i = 0;
	while (pivots[i])
	{
		last_index = get_last_index(bundle, pivots[i]);
		if (last_index == bundle->list_a->index)
			handel_first(bundle, pivots[i]);
		else
		{
			handel_first(bundle, pivots[i]);
			while (last_index != bundle->list_a->index)
				handel_first(bundle, pivots[i]);
			handel_first(bundle, pivots[i]);
		}
		rrb(bundle, 1);
		i++;
	}
	sort_list_a(bundle);
	return (pivots);
}
