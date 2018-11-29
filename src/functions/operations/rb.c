#include "libft.h"
#include "push_swap.h"

static void	save_it(t_bundle *bundle)
{
	if (bundle->operations_length > 2
		&& bundle->operations[bundle->operations_length - 2] == RRB
		&& (bundle->operations[bundle->operations_length - 1] == RA
			|| bundle->operations[bundle->operations_length - 1] == RRA
			|| bundle->operations[bundle->operations_length - 1] == SA))
	{
		bundle->operations[bundle->operations_length - 2] =\
			bundle->operations[bundle->operations_length - 1];
		bundle->operations_length--;
	}
	else if (bundle->operations_length > 0 &&
		bundle->operations[bundle->operations_length - 1] == 7)
		bundle->operations_length--;
	else if (bundle->operations[bundle->operations_length - 1] == RA)
		bundle->operations[bundle->operations_length - 1] = RR;
	else
	{
		bundle->operations[bundle->operations_length] = 4;
		bundle->operations_length++;
	}
}

void	rb(t_bundle *bundle, int save)
{
	t_numlist	*tmp;
	t_numlist	*tmp2;

	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b;
	bundle->list_b = bundle->list_b->next;
	tmp2 = bundle->list_b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = 0;
	bundle->last_a = getlast(bundle->list_a);
	bundle->last_b = getlast(bundle->list_b);
	if (save)
		save_it(bundle);
}
