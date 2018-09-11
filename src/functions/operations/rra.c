#include "libft.h"
#include "push_swap.h"

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
	if (save)
	{
		bundle->operations[bundle->operations_length] = 6;
		bundle->operations_length++;
	}
}
