#include "libft.h"
#include "push_swap.h"

void	sort_segment(t_bundle *bundle, t_numlist *end)
{
	t_numlist	*tmp;
	int			len;

	len = 0;
/*	tmp = end->next;
	while (bundle->list_b
		&& (tmp && bundle->list_b->index != tmp->index)
		&& bundle->list_a->index == bundle->list_b->index + 1)
		pa(bundle, 1);
	if (!bundle->list_b || (tmp && bundle->list_b->index == tmp->index))
		return ;*/
	tmp = bundle->list_b;
	while (tmp && tmp->index != end->index && len < 3)
	{
		len++;
		tmp = tmp->next;
	}
//	printf("%d, %d\n", bundle->list_b->index, end->index);
//	printf("==================================%d\n", len);
//	throw(0,0);
//	printf("s++++++++++++++++++++++++++++++++++++++\n");
//	debug_bundle(bundle);

	if (len < 3)
		sort_small_segment(bundle, end);
	else
		sort_big_segment(bundle, end);

	if (!is_numlist_sorted(bundle->list_a))
	{
		printf("e++++++++++++++++++++++++++++++++++++++\n");
		debug_bundle(bundle);
		throw(0,0);
	}

}
