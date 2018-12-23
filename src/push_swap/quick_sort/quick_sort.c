#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void		quick_sort(t_bundle *bundle)
{
	int		*pivots;

	pivots = roll(bundle);
	roll_back(bundle, pivots);
	free(pivots);
}
