#include "libft.h"
#include "push_swap.h"

void	quick_sort(t_bundle *bundle)
{
	sa(bundle, 1);
}

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
	quick_sort(bundle);
	print_solutions(bundle);
	free_bundle(bundle);
	return (0);
}
 