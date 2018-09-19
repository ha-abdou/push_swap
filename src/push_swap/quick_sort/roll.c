#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		*get_pivots(int list_len)
{
	int		len;
	int		tmp;
	int		*pivots;

	len = 0;
	tmp = list_len;
	while (tmp > 3)
	{
		tmp = (tmp / 2) + (tmp % 2);
		len++;
	}
	if (!(pivots = (int*)malloc(sizeof(int) * (++len))))
		throw(0, "Error\n");
	tmp = 1;
	len = list_len;
	list_len = list_len / 2 + list_len % 2;
	pivots[0] = list_len;
	while (list_len > 3)
	{
		list_len = list_len / 2 + list_len % 2;
		if ((pivots[tmp] = pivots[tmp - 1] + list_len) >= len)
			break ;
		tmp++;
	}
	pivots[tmp] = 0;
	return (pivots);
}

void	handel_first(t_bundle *bundle, int pivot)
{
	if (bundle->list_a->index > pivot)
		ra(bundle, 1);
	else if (bundle->list_a->index == pivot)
	{
		pb(bundle, 1);
		rb(bundle, 1);
	}
	else
		pb(bundle, 1);
}

int		*roll(t_bundle *bundle)
{
	int			*pivots;
	int			last_index;
	int			i;
	//get pivots
	pivots = get_pivots(bundle->list_a_length);
	i = 0;
	while (pivots[i])
	{
		printf(RED "pivot: %s%d%s\n" , GRN, pivots[i], RESET);
		last_index = bundle->last_a->index;

		//check for first elm
//		printf(RED "-->last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
		handel_first(bundle, pivots[i]);
//		printf(RED "last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
		//check for all
//		debug_bundle(bundle);
		while (last_index != bundle->list_a->index)
		{
			handel_first(bundle, pivots[i]);
//			printf(RED "last_index:%d, current_index:%d %s\n" , last_index , bundle->list_a->index, RESET);
//			debug_bundle(bundle);
		}
		handel_first(bundle, pivots[i]);
		//rotate pivots to to of list_b
		rrb(bundle, 1);
		i++;
	}
	sort_top_list_a(bundle, bundle->last_a);
	return (pivots);
}