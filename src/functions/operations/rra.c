#include "libft.h"
#include "push_swap.h"

static void	save_it(t_bundle *bundle)
{
	if (bundle->operations_length > 2
		&& bundle->operations[bundle->operations_length - 2] == RA
		&& (bundle->operations[bundle->operations_length - 1] == RB
			|| bundle->operations[bundle->operations_length - 1] == RRB
			|| bundle->operations[bundle->operations_length - 1] == SB))
	{
		bundle->operations[bundle->operations_length - 2] =\
			bundle->operations[bundle->operations_length - 1];
		bundle->operations_length--;
	}
	else if (bundle->operations[bundle->operations_length - 1] == RRB)
		bundle->operations[bundle->operations_length - 1] = RRR;
	else if (bundle->operations_length > 0 &&
		bundle->operations[bundle->operations_length - 1] == 3)
		bundle->operations_length--;
	else
	{
		bundle->operations[bundle->operations_length] = 6;
		bundle->operations_length++;
	}
}

void	rra(t_bundle *bundle, int save)
{
	t_numlist	*tmp;
	t_numlist	*tmp2;

	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = 0;
	tmp2->next = bundle->list_a;
	bundle->list_a = tmp2;
	bundle->last_a = getlast(bundle->list_a);
	bundle->last_b = getlast(bundle->list_b);
	if (save)
		save_it(bundle);
}
