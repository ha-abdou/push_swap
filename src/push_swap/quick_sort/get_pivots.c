#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		*get_pivots(int list_len, int start)
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
	pivots[0] = list_len + start;
	while (list_len > 3)
	{
		list_len = list_len / 2 + list_len % 2;
		if ((pivots[tmp] = pivots[tmp - 1] + list_len + start) >= len)
			break ;
		tmp++;
	}
	pivots[tmp] = 0;
	return (pivots);
}