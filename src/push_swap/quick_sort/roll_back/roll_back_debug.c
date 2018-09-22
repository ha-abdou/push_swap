#include "libft.h"
#include "push_swap.h"

void	roll_back_debug(t_bundle *bundle, int *pivots)
{
	t_numlist	*end;

	ft_putstr("start roll back\n");
	debug_bundle(bundle);
	while ((end = get_segment_b_end(bundle, pivots, bundle->last_b)))
	{
		ft_putstr("sort segment: " GRN );
		ft_putnbr(bundle->list_b->index);
		ft_putstr(RESET " to " GRN );
		ft_putnbr(end->index);
		ft_putstr( RESET "\n");
		_sort_top_list_b(bundle, end);
		//todo remove
		while (bundle->list_b && bundle->list_b->index != end->index)
			pa(bundle, 1);
		debug_bundle(bundle);
	}
	pa(bundle, 1);
}
