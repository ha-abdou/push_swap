#include "libft.h"
#include "push_swap.h"

void	sort_segment(t_bundle *bundle, t_numlist *end)
{
	t_numlist	*tmp;
	int			len;

	len = 0;
	tmp = bundle->list_b;
	while (tmp && tmp->index != end->index && len < 3)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 3)
		sort_small_segment(bundle, end);
	else
		sort_big_segment(bundle, end);
}
