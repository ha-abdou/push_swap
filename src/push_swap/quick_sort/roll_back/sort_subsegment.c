#include "libft.h"
#include "push_swap.h"


static  int			*roll_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;

	sub_pivots = get_pivots(bundle->list_b->index - end->index, end->index);//2
	print_pivots(sub_pivots, "sub_pivots:\n");


	pa(bundle, 1);
	tmp = bundle->list_a;
	i = 0;
	printf("len:%d ,start: %d\n", bundle->list_b->index - end->index, end->index);

	while (bundle->list_b->index != end->index)
	{
		if (bundle->list_b->index > sub_pivots[i])
			pa(bundle, 1);
		else
			rb(bundle, 1);
	}

	while (bundle->last_b->index > bundle->list_b->index)
		rrb(bundle, 1);
	i++;

	//todo to list_a elm to list_b

	while (sub_pivots[i])
	{
		printf("todo\n");
		throw(0, 0);
	}
	sort_top_list_a(bundle, tmp);

	//todo roll_back_subsegment: for each sublist aply _sort_subsegment
	return (sub_pivots);
}

void	_sort_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;


	ft_putstr("sort_subsegment:\n");
	tmp = bundle->list_a;
	sub_pivots = roll_subsegment(bundle, end);
//	roll_back_subsegment(bundle, sub_pivots, end);
}
