#include "libft.h"
#include "push_swap.h"

void	sb(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;

	bundle = (t_bundle*)self;
	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b->next;
	bundle->list_b->next = bundle->list_b->next->next;
	tmp->next = bundle->list_b;
	bundle->list_b = tmp;
}
