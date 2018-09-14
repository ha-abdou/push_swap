#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void		quick_sort(t_bundle *bundle)
{
	int		*pivots;
	int		i;

	pivots = roll(bundle);
	i = 0;
	while (pivots[i])
	{
		printf("->%d\n", pivots[i]);
		i++;
	}
	debug_bundle(bundle);
//	roll_back(bundle, pivots);
	free(pivots);
}
