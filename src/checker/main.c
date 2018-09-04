#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	print_numlist(t_numlist *list)
{
	if (!list)
		return ;
	ft_putnbr(list->value);
	ft_putstr(" ");
	if (list->next)
		print_numlist(list->next);
}

void	debug_bundle(t_bundle *bundle)
{
	ft_putstr("----------*----------\n");
	ft_putstr("stack A: ");
	print_numlist(bundle->list_a);
	ft_putstr("\nstack B: ");
	print_numlist(bundle->list_b);
	ft_putstr("\n");
}

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	char		*str;
	
	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv[1]);

//	debug_bundle(bundle);

	while (get_next_line(0, &str))
	{
		bundle->apply_function(bundle, str);
	}

	debug_bundle(bundle);
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

/*
int main(int argc, char const **argv)
{
	char *str;
	t_bundle *bundle;

	ft_putstr(argv[1]);
	ft_putstr("\n");
	while (get_next_line(0, &str))
	{
		ft_putstr(str);
	}
	ft_putstr("\n");
	return (argc - argc + bundle -bundle);
}
*/