#include "libft.h"
#include "push_swap.h"

t_numlist	*get_elm_by_index(t_bundle *bundle, int index)
{
	t_numlist	*tmp;

	tmp = bundle->list_a;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}