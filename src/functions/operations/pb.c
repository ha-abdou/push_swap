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
	bundle->list_a_length--;
	bundle->list_b_length++;
	bundle->last_a = getlast(bundle->list_a);
	bundle->last_b = getlast(bundle->list_b);
	if (save)
	{
		if (bundle->operations_length > 0 &&
			bundle->operations[bundle->operations_length - 1] == 1)
			bundle->operations_length--;
		else
		{
			bundle->operations[bundle->operations_length] = 2;
			bundle->operations_length++;
		}
	}
}
