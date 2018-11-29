#include "libft.h"
#include "push_swap.h"

static void		f_1(t_bundle *bundle, int *pivots, t_numlist *stop, int i)
{
	t_numlist	*tmp;

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

void			roll_back_segment(t_bundle *bundle, int *pivots,\
t_numlist *stop)
{
	int			i;
	t_numlist	*tmp;

	i = 0;
	while (pivots[i])
		i++;
	i--;
	pa(bundle, 1);
	if (i <= 0)
	{
		if (!stop)
			sort_segment(bundle, bundle->last_b);
		else
		{
			tmp = bundle->list_b;
			while (tmp->next->index != stop->index)
				tmp = tmp->next;
			sort_segment(bundle, tmp);
		}
		return ;
	}
	f_1(bundle, pivots, stop, i - 1);
}
