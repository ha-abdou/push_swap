NAME		= push_swap
CHECKER		= checker
LIBFT		= libft/libft.a
CC			= gcc
INC			= -I libft/includes -I includes
FLAGS		= -Wall -Wextra $(INC)

OBJ			= src/functions/is_sorted.o\
src/functions/run_stackops.o\
src/functions/create_bundle.o\
src/functions/numlist/create_numlist.o\
src/functions/throw.o\
src/functions/debug.o\
src/functions/numlist/create_elm.o\
src/functions/numlist/numlist_push.o\
src/functions/numlist/numlist_print.o\
src/functions/numlist/is_numlist_sorted.o\
src/functions/print_solutions.o\
src/functions/free_bundle.o\
src/push_swap/quick_sort/roll.o\
src/push_swap/quick_sort/quick_sort.o\
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
src/functions/operations/ss.o

CK_OBJ		= src/checker/main.o

PS_OBJ		= src/push_swap/main.o\
src/push_swap/simple_sort.o

$(NAME): $(OBJ) $(CK_OBJ) $(PS_OBJ)
	@make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(CK_OBJ) $(LIBFT) -o $(CHECKER)
	$(CC) $(FLAGS) $(OBJ) $(PS_OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f *.o
	/bin/rm -f */*.o
	/bin/rm -f */*/*.o
	/bin/rm -f */*/*/*.o
	/bin/rm -f */*/*/*/*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re