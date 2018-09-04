#include "libft.h"
#include "push_swap.h"

void	numlist_push(t_numlist *list, t_numlist *elm, int index)
{
	while (list->next)
	{
		if (list->value == elm->value)
			throw(0, "error\n");
		list = list->next;
		index++;
	}
	list->next = elm;
	list->index = index;
}
