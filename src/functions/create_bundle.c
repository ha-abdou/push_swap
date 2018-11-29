#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	list_len(t_numlist *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_numlist	*getlast(t_numlist *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

t_bundle	*create_bundle(const char *str)
{
	t_bundle	*bundle;

	if (!(bundle = (t_bundle *)malloc(sizeof(t_bundle))))
		throw(0, 0);
	if (!(bundle->operations = (int*)malloc(sizeof(int) * OPS_BUUFER_LENGTH)))
		throw(0, 0);
	bundle->operations_length = 0;
	bundle->is_sorted = &is_sorted;
	if (!(bundle->list_a = create_numlist(str)))
		throw(0, "Error\n");
	bundle->list_a_length = list_len(bundle->list_a);
	bundle->last_a = getlast(bundle->list_a);
	bundle->list_b = 0;
	bundle->last_b = 0;
	bundle->list_b_length = 0;
	return (bundle);
}
