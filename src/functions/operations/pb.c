#include "libft.h"
#include "push_swap.h"

void	pb(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;

	bundle = (t_bundle*)self;
	if (!bundle->list_a)
		return ;
	tmp = bundle->list_a;
	bundle->list_a = bundle->list_a->next;
	tmp->next = bundle->list_b;
	bundle->list_b = tmp;
}
