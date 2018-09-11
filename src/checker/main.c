#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	char		*str;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);
	while (get_next_line(0, &str))
		run_stackops(str, bundle);
	free(str);
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_bundle(bundle);
	return (0);
}
