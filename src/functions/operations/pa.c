#include "libft.h"
#include "push_swap.h"

void	pa(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;

	bundle = (t_bundle*)self;
	if (!bundle->list_b)
		return ;
	tmp = bundle->list_b;
	bundle->list_b = bundle->list_b->next;
	tmp->next = bundle->list_a;
	bundle->list_a = tmp;
}
