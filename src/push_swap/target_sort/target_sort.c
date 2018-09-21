#include "libft.h"
#include "push_swap.h"

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
		while (i--)
			rra(bundle, 1);
	}
	else
	{
		while (i--)
			ra(bundle, 1);
	}
	pb(bundle, 1);
	if (bundle->list_b->next && bundle->list_b->index - 1 != bundle->list_b->next->index)
		rb(bundle, 1);
}

t_numlist	*get_best(t_bundle *bundle, t_tsort big_next, t_tsort small_next)
{
	if (!big_next.elm)
		return (small_next.elm);
	if (!small_next.elm)
		return (big_next.elm);
	if (small_next.index < big_next.index)
	{
		if (small_next.index < bundle->list_a_length - big_next.index + 1)
			return (small_next.elm);
		return (big_next.elm);		
	}
	if (big_next.index < bundle->list_a_length - small_next.index + 1)
		return (big_next.elm);
	return (small_next.elm);
}

void		set_near_tow(t_bundle *bundle, t_tsort *big_next, t_tsort *small_next)
{
	t_numlist	*tmp;
	int			i;

	tmp = bundle->list_a;
	while (tmp)
	{
		if (tmp->index + 1 == bundle->last_b->index)
		{
			small_next->elm = tmp;
			small_next->index = i;
		}
		else if (tmp->index - 1 ==  bundle->list_b->index)
		{
			big_next->elm = tmp;
			big_next->index = i;
		}
		i++;
		tmp = tmp->next;
	}
}

t_numlist	*get_near_one(t_bundle *bundle)
{
	t_tsort		big_next;
	t_tsort		small_next;

	small_next.index = 0;
	big_next.index = 0;
	small_next.elm = 0;
	big_next.elm = 0;
	set_near_tow(bundle, &big_next, &small_next);
	return (get_best(bundle, big_next, small_next));
}

void		target_sort(t_bundle *bundle, int i)
{
	t_numlist	*elm;

	elm = get_elm_by_index(bundle, i);
	push_to_b(bundle, bundle->list_a);
	while (!is_numlist_sorted(bundle->list_a) && bundle->list_a_length > 2)
	{
		elm = get_near_one(bundle);
		push_to_b(bundle, elm);
	}
	if (bundle->list_a->next && bundle->list_a->index > bundle->list_a->next->index)
		sa(bundle, 1);
	while (bundle->list_b)
		pa(bundle, 1);
	while (bundle->list_a->index != 1)
		rra(bundle, 1);
}
