#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int 	main(int argc, const char **argv)
{
	t_bundle	*target_sort_bundle;
	
	if (argc < 2)
		throw(0, 0);
	target_sort_bundle = create_bundle(argv[1]);
/*	if (is_numlist_sorted(target_sort_bundle->list_a))
		return (0);*/


//	quick_sort(bundle);
//	print_solutions(bundle);

	target_sort(target_sort_bundle, target_sort_bundle->list_a->index);
	debug_bundle(target_sort_bundle);
	printf("%d\n", target_sort_bundle->operations_length);
	if (target_sort_bundle->is_sorted(target_sort_bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");



	free_bundle(target_sort_bundle);
	return (0);
}
 