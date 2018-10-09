#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int 	main(int argc, const char **argv)
{
	/*int *sub_pivots = get_pivots(6, 0);
	print_pivots(sub_pivots, "sub_pivots\n");
	throw(0,0);*/
	t_bundle	*bundle;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
/*	if (is_numlist_sorted(bundle->list_a))
		return (0);*/

	quick_sort_debug(bundle);

//	target_sort(bundle, bundle->list_a->index);

	debug_bundle(bundle);
//	printf("%d\n", bundle->operations_length);
	print_solutions(bundle);
//	printf("%s\n", bundle->operations_length);
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	//free_bundle(bundle);
	return (0);
}
/*
03 6  2
04 8  2
05 12 2.4
06 14 2.4
07 23 3.2
08 26 3.2
09 34 3.7
10 37 3.7
11 45 4
12 48 4
13 52 4

*/
