#include "libft.h"
#include "push_swap.h"

void	sb(t_bundle *bundle, int save)
{
	t_numlist	*tmp;

	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b->next;
	bundle->list_b->next = bundle->list_b->next->next;
	tmp->next = bundle->list_b;
	bundle->list_b = tmp;
	bundle->last_a = getlast(bundle->list_a);
	bundle->last_b = getlast(bundle->list_b);
	if (save)
	{
		bundle->operations[bundle->operations_length] = 10;
		bundle->operations_length++;
	}
}
