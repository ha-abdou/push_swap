#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	numlist_push(t_bundle *bundle, t_numlist *list, t_numlist *elm)
{
	t_numlist	*tmp;

	tmp = list;
	while (list->next)
	{
		if (list->value == elm->value)
		{
			free(elm);
			free_numlist(tmp);
			free(bundle);
			throw(0, "Error\n");
		}
		list = list->next;
	}
	if (list->value == elm->value)
	{
		free(elm);
		free_numlist(tmp);
		free(bundle);
		throw(0, "Error\n");
	}
	list->next = elm;
}
