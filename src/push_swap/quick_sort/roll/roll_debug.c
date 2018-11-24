#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	print_pivot(int i, int pivot)
{
	ft_putstr(GRN);
	ft_putnbr(i);
	ft_putstr(":");
	ft_putnbr(pivot);
	ft_putstr("\n");
	ft_putstr(RESET);
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

static void	_sort_top_list_a(t_bundle *bundle)
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
		if (bundle->list_a->index > bundle->list_a->next->index)
			sa(bundle, 1);
		if (bundle->last_a->index < bundle->list_a->next->index)
		{
			ra(bundle, 1);
			sa(bundle, 1);
		}
	}
}

int			*roll_debug(t_bundle *bundle)
{
	int			*pivots;
	int			last_index;
	int			i;

	debug_bundle(bundle);
	pivots = get_pivots(bundle->list_a_length, 0);
	print_pivots(pivots, "roll pivots:\n");
	i = 0;
	ft_putstr("start roll:\n");
	while (pivots[i])
	{
		print_pivot(i, pivots[i]);
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
		debug_bundle(bundle);
	}
	_sort_top_list_a(bundle);
	print_pivots(pivots, "roll pivots:\n");
	debug_bundle(bundle);
	ft_putstr("-------------end roll-------------\n");
	return (pivots);
}
