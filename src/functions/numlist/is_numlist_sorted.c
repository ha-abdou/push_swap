#include "libft.h"
#include "push_swap.h"

int		is_numlist_sorted(t_numlist *list)
{
	if (!list->next)
		return (1);
	if (list->index != list->next->index - 1)
		return (0);
	return (is_numlist_sorted(list->next));
}