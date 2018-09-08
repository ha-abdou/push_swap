#include "libft.h"
#include "push_swap.h"

void	rb(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;
	t_numlist	*tmp2;

	bundle = (t_bundle*)self;
	if (!bundle->list_b || !bundle->list_b->next)
		return ;
	tmp = bundle->list_b;
	bundle->list_b = bundle->list_b->next;
	tmp2 = bundle->list_b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = 0;
}
