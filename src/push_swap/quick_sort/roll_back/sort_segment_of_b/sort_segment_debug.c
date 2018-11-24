#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	sort_segment_debug(t_bundle *bundle, t_numlist *end)
{
	//todo while in place of if
	/*if (bundle->list_a->index == bundle->list_b->index + 1)
		pa(bundle, 1);*/
/*	if (!end->next && bundle->list_a->index > 4)
		sort_last_segment_debug(bundle, end);
	else */
	t_numlist	*tmp;
	int			len;

	len = 0;
	tmp = bundle->list_b;
	while (tmp && tmp->index != end->index && len < 3)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 3)
		sort_small_segment_debug(bundle, end);
	else
		sort_big_segment(bundle, end);
}
