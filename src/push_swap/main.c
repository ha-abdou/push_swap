#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	test();

int 	main(int argc, const char **argv)
{
//	print_pivots(get_pivots(4, 11), "get_pivots_reverse\n");
//	test(argc, argv);
//	throw(0,0);

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

void	test(int argc, const char **argv)
{
//	char		*str = "9 8 3 12 5 14 7 2 1 10 11 4 13 6 15 16 17 18 19 20";
	t_bundle	*bundle = create_bundle(argv[1]);
	int			i = ft_atoi(argv[2]);

	while (--i >= 0)
		pb(bundle, 1);
	//debug_bundle(bundle);
	sort_segment_debug(bundle, bundle->last_b);
	debug_bundle(bundle);
	print_solutions(bundle);
	throw(0,0);
}
