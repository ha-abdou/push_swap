#include "libft.h"
#include "push_swap.h"

void	_roll_back_debug(t_bundle *bundle, int *pivots)
{
	t_numlist	*end;

	ft_putstr("start roll back\n");
	debug_bundle(bundle);
	while ((end = get_segment_b_end(bundle, pivots, bundle->last_b)))
	{
		ft_putstr("(roll back) sort segment: " GRN );
		ft_putnbr(bundle->list_b->index);
		ft_putstr(RESET " to " GRN );
		ft_putnbr(end->index);
		ft_putstr( RESET "\n");
		sort_segment_debug(bundle, end);//+++++
		//_sort_top_list_b(bundle, end);
		//todo remove
		/*
		while (bundle->list_b && bundle->list_b->index != end->index)
			pa(bundle, 1);*/
		debug_bundle(bundle);
	}
	pa(bundle, 1);
}

void	roll_back_debug(t_bundle *bundle, int *pivots)
{
	t_numlist	*end;
	int			min_index;
	int			i;

	ft_putstr("start roll back\n");
	i = 0;
	while (pivots[i])
		i++;
	i--;
	while (i >= 0)
	{
		min_index = 1;
		if (i > 0)
			min_index = pivots[i - 1];
		end = bundle->list_b;
		while (end->next->index != min_index)
			end = end->next;
		pa(bundle, 1);
		if (min_index == 1)
			end = bundle->last_b;
		printf("(roll back) sort segment: %s%d to %d%s\n", GRN, bundle->list_b->index, end->index, RESET);
		sort_segment_debug(bundle, end);
		printf("(roll back) sort segment end **********\n");
		debug_bundle(bundle);
		i--;
	}
	throw(0,0);
}
