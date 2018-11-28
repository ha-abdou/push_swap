#include "libft.h"
#include "push_swap.h"

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
	if (is_numlist_sorted(bundle->list_a))
		return (0);
	quick_sort(bundle);
	print_solutions(bundle);
	return (0);
}
