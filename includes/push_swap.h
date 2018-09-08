#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OPS_BUUFER_LENGTH 5000

typedef struct s_numlist
{
	int					value;
	int					index;
	struct s_numlist	*next;
} t_numlist;

typedef struct s_bundle
{
	void		(*apply_function)(struct s_bundle *bundle, char *str);
	int			(*is_sorted)(struct s_bundle *bundle);
	int			*operations;
	int			operations_length;
	t_numlist	*list_a;
	int			list_a_length;
	t_numlist	*list_b;
	int			list_b_length;
} t_bundle;

t_bundle	*create_bundle(const char *str);
int			is_sorted(struct s_bundle *bundle);
void		throw(int code, char *msg);
t_numlist	*create_numlist(const char *str);
t_numlist	*create_numlist_elm(char *str);
void		numlist_push(t_numlist *list, t_numlist *elm, int index);
void		print_numlist(t_numlist *list);
void		debug_bundle(t_bundle *bundle);
void		run_stackops(char *str, t_bundle *bundle);

void		pa(void *self);
void		pb(void *self);
void		ra(void *self);
void		rb(void *self);
void		rr(void *self);
void		rra(void *self);
void		rra(void *self);
void		rrr(void *self);
void		sa(void *self);
void		sb(void *self);
void		sss(void *self);

#endif
