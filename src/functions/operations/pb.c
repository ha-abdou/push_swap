#include "libft.h"
#include "push_swap.h"

void	pb(t_bundle *bundle, int save)
{
	t_numlist	*tmp;
	
	if (!bundle->list_a)
		return ;
	tmp = bundle->list_a;
	bundle->list_a = bundle->list_a->next;
	tmp->next = bundle->list_b;
	bundle->list_b = tmp;
	if (save)
	{
		bundle->operations[bundle->operations_length] = 2;
		bundle->operations_length++;
	}
}
