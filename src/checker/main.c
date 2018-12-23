#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

char	*reader()
{
	int		n;
	char	*buff;
	char	*str;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * 5001)))
		throw(0, "Error\n");
	if (!(str = (char*)malloc(sizeof(char) * 1)))
		throw(0, "Error\n");
	buff[0] = '\0';
	str[0] = '\0';
	while ((n = read(0, buff, 5000)))
	{
		if (n == -1)
			throw(0, "Error\n");
		buff[n] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			throw(0, "Error\n");
		free(tmp);
	}
	free(buff);
	return (str);
}

static void	free_mem(t_bundle *bundle, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free_bundle(bundle);
}

static char	**get_tab()
{
	char	*str;
	char	**tab;

	str = reader();
	if (!(tab = ft_strsplit(str, '\n')))
		throw(0, "Error\n");
	free(str);
	return (tab);
}

int 	main(int argc, const char **argv)
{
	t_bundle	*bundle;
	char		**tab;
	int			i;

	if (argc < 2)
		throw(0, 0);
	bundle = create_bundle(argv, argc);
	i = 0;
	tab = get_tab();
	while (tab[i])
	{
		if (!run_stackops(tab[i], bundle))
		{
			free_mem(bundle, tab);
			throw(0, "Error\n");
		}
		i++;
	}
	if (bundle->is_sorted(bundle))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_mem(bundle, tab);
	return (0);
}
