#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void		quick_sort(t_bundle *bundle)
{
	int		*pivots;

	pivots = roll(bundle);
//	debug_bundle_pivots(bundle, pivots);
	roll_back(bundle, pivots);
//	debug_bundle_pivots(bundle, pivots);
}
/*

void		quick_sort_debug(t_bundle *bundle)
{
	int		*pivots;

	debug_bundle(bundle);
	pivots = roll_debug(bundle);
	roll_back_debug(bundle, pivots);
	debug_bundle(bundle);
}
*/