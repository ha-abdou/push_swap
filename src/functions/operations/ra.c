#include "libft.h"
#include "push_swap.h"

void	ra(void *self)
{
	t_bundle	*bundle;
	t_numlist	*tmp;
	t_numlist	*tmp2;

	bundle = (t_bundle*)self;
	if (!bundle->list_a || !bundle->list_a->next)
		return ;
	tmp = bundle->list_a;
	bundle->list_a = bundle->list_a->next;
	tmp2 = bundle->list_a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = 0;
}
