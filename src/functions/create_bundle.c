#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_bundle	*create_bundle(const char *str)
{
	t_bundle	*bundle;

	if (!(bundle = (t_bundle *)malloc(sizeof(bundle))))
		throw(0, 0);
	if (!(bundle->operations = (int *)malloc(sizeof(int))))
		throw(0, 0);
	bundle->operations_length = 0;
	bundle->apply_function = &apply_function;
	bundle->is_sorted = &is_sorted;
//	ini_stackops(bundle);
	bundle->list_a = create_numlist(str);
	printf("--->%d\n", bundle->list_a->value);
	bundle->list_a_length = bundle->list_a->index + 1;
	bundle->list_b = create_numlist(0);
	bundle->list_b_length = 0;
	return (bundle);
}
