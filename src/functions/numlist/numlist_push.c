#include "libft.h"
#include "push_swap.h"

void	numlist_push(t_numlist *list, t_numlist *elm, int index)
{
	while (list->next)
	{
		list = list->next;
		index++;
	}
	list->next = elm;
}
