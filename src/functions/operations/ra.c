#include "libft.h"
#include "push_swap.h"

void	ra(t_bundle *bundle, int save)
{
	t_numlist	*tmp;
	t_numlist	*tmp2;

	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a;
	bundle->list_a = bundle->list_a->next;
	tmp2 = bundle->list_a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = 0;
	if (save)
	{
		bundle->operations[bundle->operations_length] = 3;
		bundle->operations_length++;
	}
}
