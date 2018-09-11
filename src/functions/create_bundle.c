#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_bundle	*create_bundle(const char *str)
{
	t_bundle	*bundle;

	if (!(bundle = (t_bundle *)malloc(sizeof(t_bundle))))
		throw(0, 0);
	if (!(bundle->operations = (int*)malloc(sizeof(int) * 500)))
		throw(0, 0);
	bundle->operations_length = 0;
	bundle->is_sorted = &is_sorted;
	if (!(bundle->list_a = create_numlist(str)))
		throw(0, "Error\n");
	bundle->list_a_length = bundle->list_a->index + 1;
	bundle->list_b = 0;
	bundle->list_b_length = 0;
	return (bundle);
}
