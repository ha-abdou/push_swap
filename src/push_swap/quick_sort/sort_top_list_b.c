#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void	sort_small_sublist(t_bundle *bundle, t_numlist *end)
{
	int		i;

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

int			*roll_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;

	sub_pivots = get_pivots(bundle->list_b->index - end->index, end->index);
	
	i = 0;
	while (sub_pivots[i])
	{
		printf(RED "sub_pivots: %s%d%s\n" , GRN, sub_pivots[i], RESET);
		i++;
	}


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
	while (sub_pivots[i])
	{
		printf("todo\n");
		throw(0, 0);
	}

 /*
	while (sub_pivots[i])
	{
		printf(RED "->sub_pivot: %s%d%s\n" , GRN, sub_pivots[i], RESET);
		debug_bundle(bundle);
		while (bundle->list_b->index != end->index)
		{
			if (bundle->list_b->index > sub_pivots[i])
				pa(bundle, 1);
			else
				rb(bundle, 1);
		}
		i++;
		if (!sub_pivots[i])
		{
			tmp = bundle->last_b;
			while (bundle->last_b->index > bundle->list_b->index)
				rrb(bundle, 1);
			sort_top_list_b(bundle, tmp);
			return (sub_pivots);
		}

	}*/
	return (sub_pivots);
}

static void	sort_subsegment(t_bundle *bundle, t_numlist *end)
{
	int			*sub_pivots;
	int			i;
	t_numlist	*tmp;

	tmp = bundle->list_a;
	sub_pivots = roll_subsegment(bundle, end);
	printf("sort_top_list_a :%d\n", tmp->index);
	sort_top_list_a(bundle, tmp);
	debug_bundle(bundle);

//	printf("roll_back:\n");
//	debug_bundle(bundle);
//	printf(": %d\n", bundle->operations_length);
//	printf("++++++++++++++++todo: %d, %d\n", end->index, bundle->list_b->index);
//	print_solutions(bundle);
//	throw(0, 0);
}

void		sort_top_list_b(t_bundle *bundle, t_numlist *end)
{
	//case of segment < 3 elm
	if (bundle->list_b->index - end->index <= 4)
		sort_small_sublist(bundle, end);
	else//case of big segment
		sort_subsegment(bundle, end);
}
