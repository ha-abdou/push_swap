#include "libft.h"
#include "push_swap.h"

static void	sort_small_segment(t_bundle *bundle, t_numlist *end)
{
	int		i;

	ft_putstr("sort_small_segment:\n");
	i = 0;
	pa(bundle, 1);
	while (bundle->list_b->index != end->index)
	{
		pa(bundle, 1);
		if (bundle->list_a->index + 1 != bundle->list_a->next->index)
		{
			i++;
			ra(bundle, 1);	
		}
	}
	while (i)
	{
		i--;
		rra(bundle, 1);
	}
	if (bundle->list_a->index > bundle->list_a->next->index)
		sa(bundle, 1);
	if (!bundle->list_b->next)
		pa(bundle, 1);
}

void		_sort_top_list_b(t_bundle *bundle, t_numlist *end)
{
	//case of segment < 3 elm
	if (bundle->list_b->index - end->index <= 4 && end->next)
		sort_small_segment(bundle, end);
	else//case of big segment
		_sort_subsegment(bundle, end);
}
