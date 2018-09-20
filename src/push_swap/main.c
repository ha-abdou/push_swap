#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
	debug_bundle(bundle);
//	center_sort(bundle);
//	print_solutions(bundle);
	free_bundle(bundle);
	return (0);
}
 