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

int		*__get_pivots(int list_len, int s)
{
	float	end;
	float	start;
	int		len;
	int		*pivots;

	start = s;
	end = start + list_len;
	len = 0;
	while (end - start > 3)
	{
		start =  (start + end) / 2;
		len++;
	}
	if (!(pivots = (int*)malloc(sizeof(int) * (len + 1))))
		throw(0, "Error\n");
	start = s;
	end = start + list_len;
	len = 0;
	while (end - start > 3)
	{
		start =  (start + end) / 2;
		pivots[len] = (int)start;
		len++;
	}
	pivots[len] = 0;
	//
	int	tmp;

	tmp = 0;
	len = 0;
	while (pivots[len] && pivots[len + 1] && pivots[len + 1] - pivots[len] > 4)
		len++;
//	print_pivots(pivots, "1:\n");
	if (pivots[len] && pivots[len + 1])
	{
//		printf("!%d\n", pivots[len]);
		while (pivots[len + 1] && pivots[len] + 4 <= end)
		{
			pivots[len + 1] = pivots[len] + 4;
			len++;
		}
		pivots[len + 1] = 0;
		//printf("-->%d\n", pivots[len]);

	}
	/*
	print_pivots(pivots, "dsfsdfsdfsdfs\n");
	throw(0,0);*/
	//
	return (pivots);
}

//todo check if 0 is better
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
	if (!is_numlist_sorted(bundle->list_a))
	{
		printf("roll error\n");
		debug_bundle_pivots(bundle, pivots);
		throw(0,0);
	}
	return (pivots);
}
