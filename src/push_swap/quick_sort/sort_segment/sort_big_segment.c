#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	get_last_index(t_bundle *bundle, int pivot, int end_index)
{
	int			last_index;
	t_numlist	*list;

	list = bundle->list_b;
	last_index = end_index;
	while (list->index != end_index)
	{
		if (list->index >= pivot)
			last_index = list->index;
		list = list->next;
	}
	if (list->index >= pivot)
		last_index = list->index;
	return (last_index);
}

static void	_push_first_half(t_bundle *bundle, int pivot, int end_index)
{
	int		tmp;

	tmp = bundle->last_b->index;
	while (bundle->list_b->index != end_index)
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

static int		*roll_segment(t_bundle *bundle, int end_index, int min)
{
	int		*pivots;
	int		i;
	int		stop_1;
	int		stop_2;

	pivots = get_pivots(bundle->list_a->index - min, min - 1);
	stop_1 = bundle->list_a->index;
	stop_2 = bundle->last_a->index;
	_push_first_half(bundle, pivots[0], end_index);
	i = 1;
	while (pivots[i])
	{
		while (bundle->list_a->index != stop_1)
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
		while (bundle->last_a->index != stop_2)
		{
			rra(bundle, 1);
			if (bundle->list_a->index < pivots[i])
				pb(bundle, 1);
			if (bundle->list_a->index == pivots[i])
			{
				pb(bundle, 1);
				rb(bundle, 1);
			}
		}
		rrb(bundle, 1);
		i++;
	}
	while (bundle->last_a->index != stop_2)
		rra(bundle, 1);
	return (pivots);
}

static int		_get_min(t_bundle *bundle, int end_index)
{
	t_numlist	*tmp;
	int			min;

	tmp = bundle->list_b;
	min = end_index;
	while (tmp && tmp->index != end_index)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

static void	roll_back_segment(t_bundle *bundle, int *pivots, t_numlist *stop)
{
	int			min_index;
	int			stop_index;
	int			i;
	t_numlist	*tmp;

//	ft_putstr("start roll_back_segment\n");
//	debug_bundle_pivots(bundle, pivots);
	i = 0;
	while (pivots[i])
		i++;
	i--;

	pa(bundle, 1);
	if (i <= 0)
	{
		if (!stop)
		{
			
			sort_segment(bundle, bundle->last_b);
		}
		else
		{
			
			tmp = bundle->list_b;
			while (tmp->next->index != stop->index)
				tmp = tmp->next;
			sort_segment(bundle, tmp);
		}
//		debug_bundle(bundle);
		return ;
	}
	i--;
	while (i >= 0)
	{
		tmp = bundle->list_b;
		while (tmp->next->index > pivots[i])
			tmp = tmp->next;
		sort_segment(bundle, tmp);
		i--;
	}
	if (!stop)
		sort_segment(bundle, bundle->last_b);
	else
	{
		tmp = bundle->list_b;
		while (tmp->next->index != stop->index)
			tmp = tmp->next;
		sort_segment(bundle, tmp);
	}
}


void	sort_big_segment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	t_numlist	*stop;
	t_numlist	*tmp;

//	ft_putstr("sort big segment:\n");
	tmp = bundle->list_a;
	stop = end->next;
	sub_pivots = roll_segment(bundle, end->index, _get_min(bundle, end->index));
	sort_top_list_a(bundle, tmp);
	if (!is_numlist_sorted(bundle->list_a))
	{
		printf("roll segment error\n");
		debug_bundle(bundle);
		throw(0,0);
	}

	roll_back_segment(bundle, sub_pivots, stop);
//	printf("%s######%s\n", RED, RESET);
//	debug_bundle_pivots(bundle, sub_pivots);
//	printf("%s######%s\n", RED, RESET);
	if (!is_numlist_sorted(bundle->list_a))
	{
		printf("sort big segment error\n");
		debug_bundle(bundle);
		throw(0,0);
	}
}
