#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int			abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void		push_to_b(t_bundle *bundle, t_numlist *elm)
{
	int			i;
	t_numlist	*tmp;

	tmp = bundle->list_a;
	i = 0;
	while (tmp->index != elm->index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (bundle->list_a_length / 2))
	{
		i = bundle->list_a_length - i;
		while (i)
		{
			i--;
			rra(bundle, 1);
		}
	}
	else
	{
		while (i)
		{
			i--;
			ra(bundle, 1);
		}
	}
	pb(bundle, 1);
	if (bundle->list_b->next && bundle->list_b->index - 1 != bundle->list_b->next->index)
		rb(bundle, 1);
}
//todo rework this function
t_numlist	*get_start_point(t_bundle *bundle)
{
	int			ref;
	int			max_gap;
	t_numlist	*center;
	t_numlist	*tmp;

	max_gap = bundle->list_a_length / 5;
	ref = (bundle->list_a_length * 1) / 5;
	center = bundle->list_a;
	tmp = bundle->list_a->next;
	while (max_gap)
	{
		if (abs(tmp->index - ref) < abs(center->index - ref))
			center = tmp;
		tmp = tmp->next;
		max_gap--;
	}
	max_gap = (bundle->list_a_length / 5) * 3;
	while (max_gap)
	{
		max_gap--;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (abs(tmp->index - ref) < abs(center->index - ref))
			center = tmp;
		tmp = tmp->next;
	}
	return (center);
}

t_numlist	*get_near_one(t_bundle *bundle, t_numlist *small, t_numlist *big)
{
	int			small_index;
	int			big_index;
	t_numlist	*big_next;
	t_numlist	*small_next;
	t_numlist	*tmp;
	int			i;

	i = 0;
	small_index = 0;
	big_index = 0;
	small_next = 0;
	big_next = 0;
	tmp = bundle->list_a;
	while (tmp)
	{
//		printf("******>%d\n", tmp->index);
//		printf("*****+>%d\n", i);
		if (tmp->index + 1 == small->index)
		{
//			printf("-----*>%d\n", tmp->index);
//			printf("-----*>%d\n", i);
			small_next = tmp;
			small_index = i;
		}
		else if (tmp->index - 1 == big->index)
		{
	//		printf("-----/>%d\n", tmp->index);
		//	printf("-----/>%d\n", i);
			big_next = tmp;
			big_index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (!big_next)
		return (small_next);
	if (!small_next)
		return (big_next);
	if (small_index < big_index)
	{
		if (small_index < bundle->list_a_length - big_index + 1)
			return (small_next);
		return (big_next);		
	}
	if (big_index < bundle->list_a_length - small_index + 1)
		return (big_next);
	return (small_next);
}

void		center_sort(t_bundle *bundle)
{
	t_numlist	*elm;

	elm = get_start_point(bundle);
	push_to_b(bundle, elm);
	debug_bundle(bundle);
	while (!is_numlist_sorted(bundle->list_a) && bundle->list_a_length > 2)
	{
		elm = get_near_one(bundle, bundle->last_b, bundle->list_b);
		printf("target: %d\n", elm->index);
		push_to_b(bundle, elm);
		debug_bundle(bundle);
	}
	if (bundle->list_a->next && bundle->list_a->index > bundle->list_a->next->index)
		sa(bundle, 1);
	while (bundle->list_b)
		pa(bundle, 1);
	while (bundle->list_a->index != 1)
		rra(bundle, 1);
	printf("+++++++++++++++++\n");
	debug_bundle(bundle);
}
