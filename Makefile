NAME	= push_swap
CHECKER	= checker
LIBFT	= libft/libft.a
CC		= gcc
INC		= -I libft/includes -I includes
FLAGS	= -Wall -Wextra $(INC)

OBJ		= src/functions/apply_function.o src/functions/is_sorted.o\
src/functions/ini_stackops.o src/functions/create_bundle.o\
src/functions/numlist/create_numlist.o src/functions/throw.o\
src/functions/numlist/create_elm.o src/functions/numlist/numlist_push.o\
src/functions/operations/pb.o

CK_OBJ	= src/checker/main.o

PS_OBJ	=

$(NAME): $(OBJ) $(CK_OBJ) $(PS_OBJ)
	#make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(CK_OBJ) $(LIBFT) -o $(CHECKER)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f *.o
	/bin/rm -f */*.o
	/bin/rm -f */*/*.o
	/bin/rm -f */*/*/*.o
	/bin/rm -f */*/*/*/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re