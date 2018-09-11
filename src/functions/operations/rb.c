#include "libft.h"
#include "push_swap.h"

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
	if (save)
	{
		bundle->operations[bundle->operations_length] = 4;
		bundle->operations_length++;
	}
}
