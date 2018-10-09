#include "libft.h"
#include "push_swap.h"

static int			*roll_subsegment_last(t_bundle *bundle)
{

}

static  int			*roll_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;

	if (!end->next)
		return (roll_subsegment_last(bundle));
	if (bundle->list_a->index == bundle->list_b->index + 1)
		pa(bundle, 1);
	sub_pivots = get_pivots_forward(end->index, bundle->list_a->index - 1);//2 ,
	print_pivots(sub_pivots, "sub_pivots:\n");

	tmp = bundle->list_a;
	i = 0;
	printf("start:%d ,end: %d\n", end->next ? end->index : 0 , bundle->list_a->index - 1);

	while (bundle->list_b->index != end->index)
	{
		if (bundle->list_b->index > sub_pivots[i])
			pa(bundle, 1);
		else
			rb(bundle, 1);
	}

	while (bundle->last_b->index > end->index)
		rrb(bundle, 1);

	printf("--------------->\n");
	printf("first half::\n");
	debug_bundle(bundle);
	printf("<---------------\n");

	//todo to list_a elm to list_b
	i++;

	while (sub_pivots[i])
	{
		printf("todo\n");
		i++;
		throw(0, 0);
	}

	sort_top_list_a(bundle, tmp);


	printf("--------------->\n");
	printf("sort_top_list_a:\n");
	debug_bundle(bundle);
	printf("<---------------\n");
	//todo roll_back_subsegment: for each sublist aply _sort_subsegment
	return (sub_pivots);
}

static t_numlist	*_get(t_bundle *bundle, int sub_pivot, t_numlist *end)
{
	int			last;
	t_numlist	*tmp;

	if (sub_pivot)
		last = sub_pivot;
	else
		last = end->index;
	tmp = bundle->list_b;
	while (tmp->next && tmp->next->index >= last)
		tmp = tmp->next;
	return (tmp);
}

void		__sort_top_list_b(t_bundle *bundle, int start_index, t_numlist *end)
{
	//case of segment < 3 elm
	if (start_index - end->index <= 3 && end->next)
		sort_small_segment(bundle, end);
	else//case of big segment
		_sort_subsegment(bundle, end);
}

static void	_roll_back_subsegment(t_bundle *bundle, int *sub_pivots, t_numlist *end)
{
	int			i;
	t_numlist	*tmp;

	printf("roll_back_subsegment:\n");
	print_pivots(sub_pivots, "sub_pivots:\n");

	i = 0;
	printf("--------------------->>>>>>>>>>>>>>\n");
	while (sub_pivots[i])
	{
		tmp = _get(bundle, sub_pivots[i + 1], end);
		printf("sort_subsegment:%d ,to %d.\n", bundle->list_b->index, tmp->index);
		__sort_top_list_b(bundle, sub_pivots[i], tmp);
		debug_bundle(bundle);
		i++;
	}
	pa(bundle, 1);
	debug_bundle(bundle);
//	throw(0, 0);
}

void		_sort_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;


	ft_putstr("sort_subsegment:\n");
	tmp = bundle->list_a;
	sub_pivots = roll_subsegment(bundle, end);
	_roll_back_subsegment(bundle, sub_pivots, end);
}
