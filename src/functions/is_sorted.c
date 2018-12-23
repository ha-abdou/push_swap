#include "libft.h"
#include "push_swap.h"

int		is_sorted(t_bundle *bundle)
{
	t_numlist	*list;

	list = bundle->list_a;
	if (bundle->list_b)
		return (0);
	while (list->next)
	{
		if (list->next->value < list->value)
			return (0);
		list = list->next;
	}
	return (1);
}
