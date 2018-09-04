#include "libft.h"
#include "push_swap.h"

int		is_sorted(t_bundle *bundle)
{
	if (bundle->list_b)
		return (0);
	while (bundle->list_a->next)
	{
		if (bundle->list_a->next->value < bundle->list_a->value)
			return (0);
		bundle->list_a = bundle->list_a->next;
	}
	return (1);
}
