NAME = push_swap
SRC = tests.c\
		input_handling.c\
		list_functions.c
 
#TEST_INPUT = 1 2 3 4 5 6
TEST_INPUT = 4 5 55 232 2
#"-34 23 2"
#testing_functions.c

OBJ = $(SRC:.c=.o)
SUBDIR = LIBFT
LIBFT = $(SUBDIR)/LIBFT.a


CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.PHONY: all bonus clean fclean re aa aac va seelib norm normb 
all: $(NAME) clean
 
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -g $(OBJ) $(LIBFT) -o $(NAME) 
	@echo $(NAME) created
	
$(LIBFT):
	@+$(MAKE) -C $(SUBDIR)
	@echo "MAKE libft_expanded.a file"

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -rf *.o
	@echo "clean done"
	$(MAKE) $@ -C $(SUBDIR)
	$(MAKE) $@ -C $(SUBDIR)/libft

fclean: clean
	@rm -f $(NAME)
	$(MAKE) $@ -C $(SUBDIR)
	$(MAKE) $@ -C $(SUBDIR)/libft
	@echo "fclean done"

re: fclean all
	@echo "\nRecompilation done"

aa: re
	@echo Executing programm
	./$(NAME) $(TEST_INPUT)

aac: re
	@echo Executing programm with "checker_linux"
	./$(NAME) $(TEST_INPUT) | ./checker_linux $(TEST_INPUT)

va: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST_INPUT)

debug : CFLAGS += -g
debug : fclean all

seelib:
	@ar -t $(NAME)

norm: $(SRC)
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(NAME).h
	@echo all source files checked with norminette

normb: $(norm)
	@norminette -R CheckForbiddenSourceHeader $(bon_src)
	@echo all SRC checked with norminette including bonus
