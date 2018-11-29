#include "libft.h"
#include "push_swap.h"

void	numlist_push(t_numlist *list, t_numlist *elm)
{
	while (list->next)
	{
		if (list->value == elm->value)
			throw(0, "Error\n");
		list = list->next;
	}
	if (list->value == elm->value)
		throw(0, "Error\n");
	list->next = elm;
}
