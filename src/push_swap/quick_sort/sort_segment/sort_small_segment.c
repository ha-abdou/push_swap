#include "libft.h"
#include "push_swap.h"

static void	handle_3(t_bundle *bundle)
{
	t_numlist	*e1;
	t_numlist	*e2;
	t_numlist	*e3;

	e1 = bundle->list_b;
	e2 = e1->next;
	e3 = e2->next;
	pa(bundle, 1);
	pa(bundle, 1);
	if (e2->index > e1->index)
		sa(bundle, 1);
	if (e3->index > e1->index && e3->index > e2->index)
	{
		ra(bundle, 1);
		ra(bundle, 1);
		pa(bundle, 1);
		rra(bundle, 1);
		rra(bundle, 1);
		return ;
	}
	pa(bundle, 1);
	if (bundle->list_a->next->index < bundle->list_a->index)
		sa(bundle, 1);
}

void		sort_small_segment(t_bundle *bundle, t_numlist *end)
{
	if (bundle->list_b->index == end->index)
		pa(bundle, 1);
	else if (bundle->list_b->next->index == end->index)
	{
		pa(bundle, 1);
		pa(bundle, 1);
		if (bundle->list_a->index > bundle->list_a->next->index)
			sa(bundle, 1);
	}
	else if (bundle->list_b->next->next->index == end->index)
		handle_3(bundle);
}
