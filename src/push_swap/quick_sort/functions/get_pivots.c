#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int		*get_pivots_forward(int start, int end)
{
	int		len;
	int		tmp;
	int		*pivots;

	len = 0;
	tmp = ((start + end) / 2) + ((start + end) % 2);
	while (tmp > start + 3)
	{
		tmp = ((start + tmp) / 2) + ((start + tmp) % 2);
		len++;
	}
	if (!(pivots = (int*)malloc(sizeof(int) * (++len))))
		throw(0, "Error\n");

	tmp = ((start + end) / 2) + ((start + end) % 2);
	len = 0;
	while (tmp > start + 3)
	{
		pivots[len] = tmp;
		printf("%d\n", tmp);
		tmp = ((start + tmp) / 2) + ((start + tmp) % 2);
		len++;
	}
	pivots[len] = 0;
	return (pivots);
}

int		*get_pivots(int list_len, int start)
{
	int		len;
	int		tmp;
	int		*pivots;

	len = 0;
	tmp = list_len;
	while (tmp > 3 && ++len)
		tmp = (tmp / 2) + (tmp % 2);
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
	while (len - pivots[tmp - 1] > 3)
		pivots[tmp - 1]++;
	pivots[tmp] = 0;
	return (pivots);
}