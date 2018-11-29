#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OPS_BUUFER_LENGTH 500000
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define PA  1
# define PB  2
# define RA  3
# define RB  4
# define RR  5
# define RRA 6
# define RRB 7
# define RRR 8
# define SA  9
# define SB 10
# define SS 11

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
	t_numlist	*last_a;
	int			list_a_length;
	t_numlist	*list_b;
	t_numlist	*last_b;
	int			list_b_length;
} t_bundle;

typedef struct s_tsort
{
	int			index;
	t_numlist	*elm;
} t_tsort;

t_bundle	*create_bundle(const char *str);
int			is_sorted(struct s_bundle *bundle);
void		throw(int code, char *msg);
t_numlist	*create_numlist(const char *str);
t_numlist	*create_numlist_elm(char *str);
void		numlist_push(t_numlist *list, t_numlist *elm);
void		run_stackops(char *str, t_bundle *bundle);
void		print_solutions(t_bundle *bundle);
void		free_bundle(t_bundle *bundle);
int			is_numlist_sorted(t_numlist *list);
int			*roll(t_bundle *bundle);
void		quick_sort(t_bundle *bundle);
t_numlist	*getlast(t_numlist *list);
void		roll_back(t_bundle *bundle, int *pivots);
void		sort_top_list_a(t_bundle *bundle, t_numlist *end);
int			*get_pivots(int list_len, int start);
int			abs(int num);
t_numlist	*get_elm_by_index(t_bundle *bundle, int index);
void		sort_small_segment(t_bundle *bundle, t_numlist *end);
void		sort_big_segment(t_bundle *bundle, t_numlist *end);
void		sort_segment(t_bundle *bundle, t_numlist *end);
void		roll_back_segment(t_bundle *bundle, int *pivots, t_numlist *stop);
int			*roll_segment(t_bundle *bundle, int end_index, int min);
void		pa(t_bundle *self, int save);
void		pb(t_bundle *self, int save);
void		ra(t_bundle *self, int save);
void		rb(t_bundle *self, int save);
void		rr(t_bundle *self, int save);
void		rra(t_bundle *self, int save);
void		rrb(t_bundle *self, int save);
void		rrr(t_bundle *self, int save);
void		sa(t_bundle *self, int save);
void		sb(t_bundle *self, int save);
void		ss(t_bundle *self, int save);
void		br(t_bundle *bundle, int save);
void		target_sort(t_bundle *bundle);

#endif
