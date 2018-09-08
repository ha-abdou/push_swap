#include "libft.h"
#include "push_swap.h"

void	rrb(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;
	t_numlist	*tmp2;

	bundle = (t_bundle*)self;
	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = 0;
	tmp2->next = bundle->list_b;
	bundle->list_b = tmp2;
}
