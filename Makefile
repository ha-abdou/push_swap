PUSHSWAP	= push_swap
CHECKER		= checker
LIBFT		= libft/libft.a
CC			= gcc
INC			= -I libft/includes -I includes
FLAGS		= -Wall -Wextra -Werror $(INC)

OBJ			= src/functions/is_sorted.o\
src/functions/run_stackops.o\
src/functions/create_bundle.o\
src/functions/numlist/create_numlist.o\
src/functions/throw.o\
src/functions/numlist/create_elm.o\
src/functions/numlist/numlist_push.o\
src/functions/numlist/numlist_print.o\
src/functions/numlist/is_numlist_sorted.o\
src/functions/print_solutions.o\
src/functions/free_bundle.o\
src/functions/get_elm_by_index.o\
src/push_swap/quick_sort/roll.o\
src/push_swap/quick_sort/roll_back.o\
src/push_swap/quick_sort/quick_sort.o\
src/push_swap/quick_sort/functions/get_pivots.o\
src/push_swap/quick_sort/functions/sort_top_list_a.o\
src/push_swap/quick_sort/sort_segment/sort_segment.o\
src/push_swap/quick_sort/sort_segment/sort_small_segment.o\
src/push_swap/quick_sort/sort_segment/sort_big_segment.o\
src/push_swap/quick_sort/sort_segment/roll_big_segment.o\
src/push_swap/quick_sort/sort_segment/roll_back_big_segment.o\
src/push_swap/target_sort.o\
src/functions/abs.o\
src/functions/operations/pb.o\
src/functions/operations/pa.o\
src/functions/operations/ra.o\
src/functions/operations/rb.o\
src/functions/operations/rr.o\
src/functions/operations/rra.o\
src/functions/operations/rrb.o\
src/functions/operations/rrr.o\
src/functions/operations/sa.o\
src/functions/operations/sb.o\
src/functions/operations/br.o\
src/functions/operations/ss.o

CK_OBJ		= src/checker/main.o

PS_OBJ		= src/push_swap/main.o

all: $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP): $(OBJ) $(PS_OBJ) includes/push_swap.h
	@make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(PS_OBJ) $(LIBFT) -o $(PUSHSWAP)

$(CHECKER): $(OBJ) $(CK_OBJ) includes/push_swap.h
	@make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(CK_OBJ) $(LIBFT) -o $(CHECKER)

%.o: %.c includes/push_swap.h
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ) $(PS_OBJ) $(CK_OBJ)

fclean: clean
	/bin/rm -f $(PUSHSWAP)
	/bin/rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re test