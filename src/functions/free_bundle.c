#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void		free_numlist(t_numlist *numlist)
{
	if (numlist)
	{
		free_numlist(numlist->next);
		free(numlist);
	}
}

void		free_bundle(t_bundle *bundle)
{
	free_numlist(bundle->list_a);
	free_numlist(bundle->list_b);
	free(bundle->operations);
	free(bundle);
}
