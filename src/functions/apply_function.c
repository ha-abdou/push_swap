#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	apply_function(t_bundle *bundle, char *str)
{
	int		i;

	i = 0;
	while (i < 1)
	{
		printf("-->%s, %s\n", bundle->opfunctions[0].name, str);
		if (ft_strcmp(bundle->opfunctions[i].name, str) == 0)
		{
			bundle->opfunctions[i].func(bundle);
			return ;
		}
		i++;
	}
}