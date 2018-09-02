#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OPS_BUUFER_LENGTH 5000

typedef struct s_numlist
{
	int					value;
	int					index;
	struct s_numlist	*next;
} t_numlist;

typedef struct s_stackops
{
	char	name[4];
	void	(*func)(void *bundle);
} t_stackops;

typedef struct s_bundle
{
	void		(*apply_function)(struct s_bundle *bundle, char *str);
	int			(*is_sorted)(struct s_bundle *bundle);
	t_stackops	*opfunctions;
	int			*operations;
	int			operations_length;
	t_numlist	*list_a;
	int			list_a_length;
	t_numlist	*list_b;
	int			list_b_length;
} t_bundle;

t_bundle	*create_bundle(const char *str);
void		apply_function(struct s_bundle *bundle, char *str);
int			is_sorted(struct s_bundle *bundle);
void		throw(int code, char *msg);
void		ini_stackops(t_bundle *bundle);
t_numlist	*create_numlist(const char *str);
t_numlist	*create_numlist_elm(char *str);
void		numlist_push(t_numlist *list, t_numlist *elm, int index);

//void		pa(void *bundle);
void		pb(void *self);

#endif
