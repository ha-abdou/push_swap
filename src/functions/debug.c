#include "libft.h"
#include "push_swap.h"

void	debug_bundle(t_bundle *bundle)
{
	ft_putstr("----------*----------\n");
	ft_putstr("stack A: \n");
	ft_putstr("index: ");
	print_numlist_index(bundle->list_a);
	ft_putstr("\n");
	ft_putstr("value: ");
	print_numlist(bundle->list_a);

	ft_putstr("\n");
	ft_putstr("stack B: \n");
	ft_putstr("index: ");
	print_numlist_index(bundle->list_b);
	ft_putstr("\n");
	ft_putstr("value: ");
	print_numlist(bundle->list_b);

	ft_putstr("\n");
	print_numlist(bundle->list_b);
	ft_putstr("\n\nops len: ");
	ft_putnbr(bundle->operations_length);
	ft_putstr("\n");
	ft_putstr("----------*----------\n");
	ft_putstr("\n");
}

void	print_numlist_index_pivots(t_numlist *list, int *pivots)
{
	int		i;

	i = 0;
	if (!list)
		return ;
	while (pivots[i])
	{
		if (pivots[i] == list->index)
		{
			ft_putstr(GRN);
			ft_putnbr(list->index);
			ft_putstr(RESET);
			ft_putstr(" ");
			print_numlist_index_pivots(list->next, pivots);
			return ;
		}
		i++;
	}
	ft_putnbr(list->index);
	ft_putstr(" ");
	if (list->next)
		print_numlist_index_pivots(list->next, pivots);
}

void	debug_bundle_pivots(t_bundle *bundle, int *pivots)
{
	ft_putstr("----------*----------\n");
	ft_putstr("stack A: ");
	print_numlist_index_pivots(bundle->list_a, pivots);
	ft_putstr("\n");
	ft_putstr("\nstack B: ");
	print_numlist_index_pivots(bundle->list_b, pivots);
	ft_putstr("\n\nops len: ");
	ft_putnbr(bundle->operations_length);
	ft_putstr("\n");
	ft_putstr("----------*----------\n");
	ft_putstr("\n");
}
