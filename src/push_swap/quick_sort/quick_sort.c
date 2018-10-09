#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void		quick_sort(t_bundle *bundle)
{
	int		*pivots;

	pivots = roll(bundle);
	printf("roll:\n");
	debug_bundle(bundle);
	roll_back(bundle, pivots);
	printf("roll_back:\n");
	debug_bundle(bundle);
	free(pivots);
}

void		quick_sort_debug(t_bundle *bundle)
{
	int		*pivots;

	debug_bundle(bundle);
	pivots = roll_debug(bundle);
	roll_back_debug(bundle, pivots);
	debug_bundle(bundle);
}

