#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int		get_min(t_bundle *bundle, int end_index)
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

void	sort_big_segment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	t_numlist	*stop;
	t_numlist	*tmp;

	tmp = bundle->list_a;
	stop = end->next;
	sub_pivots = roll_segment(bundle, end->index, get_min(bundle, end->index));
	sort_top_list_a(bundle, tmp);
	roll_back_segment(bundle, sub_pivots, stop);
	free(sub_pivots);
}
