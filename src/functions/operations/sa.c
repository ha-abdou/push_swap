#include "libft.h"
#include "push_swap.h"

void	sa(t_bundle *bundle, int save)
{
	t_numlist	*tmp;

	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a->next;
	bundle->list_a->next = bundle->list_a->next->next;
	tmp->next = bundle->list_a;
	bundle->list_a = tmp;
	bundle->last_a = getlast(bundle->list_a);
	bundle->last_b = getlast(bundle->list_b);
	if (save)
	{
		bundle->operations[bundle->operations_length] = 9;
		bundle->operations_length++;
	}
}
