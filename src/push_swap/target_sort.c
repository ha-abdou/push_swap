#include "libft.h"
#include "push_swap.h"

static int	get_pos(t_bundle *bundle, int index)
{
	t_numlist	*tmp;
	int			i;

	tmp = bundle->list_a;
	i = 1;
	while (tmp && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void		target_sort(t_bundle *bundle)
{
	int			min;
	int			pos;

	min = 1;
	while (!is_numlist_sorted(bundle->list_a))
	{
		pos = get_pos(bundle, min);
		if (pos > bundle->list_a_length / 2)
		{
			while (bundle->list_a->index != min)
				rra(bundle, 1);
		}
		else
		{
			while (bundle->list_a->index != min)
				ra(bundle, 1);
		}
		pb(bundle, 1);
		min++;
	}
	while (bundle->list_b)
		pa(bundle, 1);
}
