#include "libft.h"
#include "push_swap.h"

void	debug_bundle(t_bundle *bundle)
{
	ft_putstr("----------*----------\n");
	ft_putstr("stack A: ");
	print_numlist(bundle->list_a);
	ft_putstr("\nindex A: ");
	print_numlist_index(bundle->list_a);
	ft_putstr("\n");
	ft_putstr("\nstack B: ");
	print_numlist(bundle->list_b);
	ft_putstr("\nindex b: ");
	print_numlist_index(bundle->list_b);
	ft_putstr("\n");
	ft_putstr("\n");
}
