#include "libft.h"
#include "push_swap.h"

void	sa(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;

	bundle = (t_bundle*)self;
	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a->next;
	bundle->list_a->next = bundle->list_a->next->next;
	tmp->next = bundle->list_a;
	bundle->list_a = tmp;
}
