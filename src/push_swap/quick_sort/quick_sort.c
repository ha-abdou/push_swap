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
