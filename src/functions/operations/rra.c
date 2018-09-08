#include "libft.h"
#include "push_swap.h"

void	rra(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;
	t_numlist	*tmp2;

	bundle = (t_bundle*)self;
	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = 0;
	tmp2->next = bundle->list_a;
	bundle->list_a = tmp2;
}
