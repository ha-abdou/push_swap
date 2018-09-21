#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
/*	if (is_numlist_sorted(bundle->list_a))
		return (0);*/


	quick_sort_debug(bundle);

//	target_sort(bundle, bundle->list_a->index);

	debug_bundle(bundle);
	printf("%d\n", bundle->operations_length);
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");



	free_bundle(bundle);
	return (0);
}
 