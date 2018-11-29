#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		*get_pivots(int list_len, int s)
{
	float	end;
	float	start;
	int		len;
	int		*pivots;

	start = s;
	end = start + list_len;
	len = 0;
	while (end - start > 3)
	{
		start =  (start + end) / 2;
		len++;
	}
	if (!(pivots = (int*)malloc(sizeof(int) * (len + 1))))
		throw(0, "Error\n");
	start = s;
	len = 0;
	while (end - start > 3)
	{
		start =  (start + end) / 2;
		pivots[len] = (int)start;
		len++;
	}
	pivots[len] = 0;
	return (pivots);
}
