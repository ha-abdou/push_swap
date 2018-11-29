#include "libft.h"
#include "push_swap.h"

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	t_bundle	*bundle_2;
	
	if (argc < 2)
		throw(0, "Error\n");
	bundle = create_bundle(argv[1]);
	if (is_numlist_sorted(bundle->list_a))
		return (0);
	bundle_2 = create_bundle(argv[1]);
	if (bundle->list_a_length <= 100)
		target_sort(bundle_2);
	quick_sort(bundle);
	if (bundle->list_a_length <= 100 &&
		bundle_2->operations_length < bundle->operations_length)
		print_solutions(bundle_2);
	else
		print_solutions(bundle);
	free_bundle(bundle);
	free_bundle(bundle_2);
	return (0);
}
