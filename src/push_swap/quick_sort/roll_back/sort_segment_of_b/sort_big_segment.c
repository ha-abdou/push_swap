#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	_push_first_half(t_bundle *bundle, int pivot, int end_index)
{
	int		tmp;

//	printf("\n****    push first half\n");
//	debug_bundle(bundle);
	tmp = bundle->last_b->index;
	while (bundle->list_b->index != end_index)
	{
		if (bundle->list_b->index > pivot)
			pa(bundle, 1);
		else
			rb(bundle, 1);
	}
	if (bundle->list_b->index > pivot)
		pa(bundle, 1);
	if (end_index != tmp)
		while (bundle->last_b->index != tmp)
			rrb(bundle, 1);
//	debug_bundle(bundle);
//	printf("\n****    end push first half\n");
}

int		*roll_segment(t_bundle *bundle, int end_index, int min)
{
	int		*pivots;
	int		i;
	int		stop_1;
	int		stop_2;

	debug_bundle(bundle);
	pivots = get_pivots(bundle->list_a->index - min, min);
	printf("roll big segment: %d, %d\n", bundle->list_a->index - 1, min);

	print_pivots(pivots, "sup pivots big segment\n");

	//push first half

	stop_1 = bundle->list_a->index;
	stop_2 = bundle->last_a->index;
	_push_first_half(bundle, pivots[0], end_index);
	//
	i = 1;
	while (pivots[i])
	{
		while (bundle->list_a->index != stop_1)
		{
			if (bundle->list_a->index < pivots[i])
				pb(bundle, 1);
			else
				ra(bundle, 1);
		}
		i++;
		if (!pivots[i])
			break ;
		while (bundle->last_a->index != stop_2)
		{
			rra(bundle, 1);
			if (bundle->list_a->index < pivots[i])
				pb(bundle, 1);
		}
		i++;
	}
	while (bundle->last_a->index != stop_2)
		rra(bundle, 1);
	return (pivots);
}

int		_get_min(t_bundle *bundle, int end_index)
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

void	roll_back_segment(t_bundle *bundle, int *pivots, t_numlist *stop)
{
	int			min_index;
	int			stop_index;
	int			i;
	t_numlist	*tmp;

	ft_putstr("start roll_back_segment\n");
	debug_bundle(bundle);
	i = 0;
	while (pivots[i])
		i++;
	i--;
	if (i <= 0)
	{
		if (!stop)
			sort_segment_debug(bundle, bundle->last_b);
		else
		{
			tmp = bundle->list_b;
			while (tmp->next->index != stop->index)
				tmp = tmp->next;
			sort_segment_debug(bundle, tmp);
		}
		debug_bundle(bundle);
		return ;
	}
	i--;
	while (i >= 0)
	{
		tmp = bundle->list_b;
		while (tmp->next->index > pivots[i])
			tmp = tmp->next;
		sort_segment_debug(bundle, tmp);
		i--;
	}
	if (!stop)
		sort_segment_debug(bundle, bundle->last_b);
	else
	{
		tmp = bundle->list_b;
		while (tmp->next->index != stop->index)
			tmp = tmp->next;
		sort_segment_debug(bundle, tmp);
	}

/*
	t_numlist	*end;

	ft_putstr("start roll_back_segment\n");
	debug_bundle(bundle);
	while ((end = get_segment_b_end(bundle, pivots, bundle->last_b)))
	{
		ft_putstr("sort segment: " GRN );
		ft_putnbr(bundle->list_b->index);
		ft_putstr(RESET " to " GRN );
		ft_putnbr(end->index);
		ft_putstr( RESET "\n");
		sort_segment_debug(bundle, end);
		debug_bundle(bundle);
	}
	pa(bundle, 1);
*/
}


void	sort_big_segment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	t_numlist	*stop;
	t_numlist	*tmp;

	ft_putstr("sort big segment:\n");
	tmp = bundle->list_a;
	stop = end->next;
	sub_pivots = roll_segment(bundle, end->index, _get_min(bundle, end->index));
	sort_top_list_a(bundle, tmp);
	debug_bundle(bundle);
	roll_back_segment(bundle, sub_pivots, stop);
	debug_bundle(bundle);
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
