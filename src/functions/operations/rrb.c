#include "libft.h"
#include "push_swap.h"

void	rrb(t_bundle *bundle, int save)
{
	t_numlist	*tmp;
	t_numlist	*tmp2;

	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = 0;
	tmp2->next = bundle->list_b;
	bundle->list_b = tmp2;
	if (save)
	{
		bundle->operations[bundle->operations_length] = 7;
		bundle->operations_length++;
	}
}
