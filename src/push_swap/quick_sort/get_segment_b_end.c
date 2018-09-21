#include "libft.h"
#include "push_swap.h"

t_numlist	*get_segment_b_end(t_bundle *bundle, int *pivots)
{
	int			i;
	t_numlist	*tmp;

	if (!bundle->list_b)
		return (0);
	i = 0;
	//get the pivot index
	while (pivots[i + 1] && pivots[i + 1] != bundle->list_b->index)
		i++;
	//
	if (!pivots[i + 1])
		return (bundle->last_b);
	//get the matching elm from list_b
	tmp = bundle->list_b->next;
	while (tmp)
	{
		if (tmp->index == pivots[i])
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
