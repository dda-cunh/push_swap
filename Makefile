.SILENT:
NAME	= 	push_swap

BONUS_N	=	checker

CC 		= 	clang

CFLAGS	= 	-Wall -Wextra -Werror

RM 		= 	rm -f

SRC		= 	push_swap.c utils.c struct.c stack_utils.c\
			ops.c ops_joint.c lines_per_functionxd.c sort.c

OBJ 	= 	$(SRC:%.c=%.o)

BONUS_S =	push_swap_bonus.c $(filter-out lines_per_functionxd.c push_swap.c, $(SRC))

BONUS_O =	$(BONUS_S:%.c=%.o)

GREEN	= 	\033[0;32m

RESET	=	\033[0m

$(NAME):	$(OBJ)
			make -C libft
			$(CC) $(OBJ) -Llibft -lft -o $(NAME) -g3 -fsanitize=address
			make fclean -C libft
			make done

$(OBJ): 	$(SRC)
			$(CC) -c $(CFLAGS) $(SRC)

all: 		$(NAME)
			make bonus
clean:	
			$(RM) $(OBJ) push_swap_bonus.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

done:
			printf "															 	\n"
			printf "$(GREEN)	$(NAME)							 			$(RESET)\n"
			printf "$(GREEN)                             _  _             _ $(RESET)\n"
			printf "$(GREEN)                            (_)| |           | |$(RESET)\n"
			printf "$(GREEN)  ____   ___   ____   ____   _ | |  ____   _ | |$(RESET)\n"
			printf "$(GREEN) / ___) / _ \ |    \ |  _ \ | || | / _  ) / || |$(RESET)\n"
			printf "$(GREEN)( (___ | |_| || | | || | | || || |( (/ / ( (_| |$(RESET)\n"
			printf "$(GREEN) \____) \___/ |_|_|_|| ||_/ |_||_| \____) \____|$(RESET)\n"
			printf "$(GREEN)                     |_|                        $(RESET)\n"
			printf "																\n"

$(BONUS_N):	$(BONUS_O)
			make -C libft
			$(CC) $(OBJ) -Llibft -lft -o $(BONUS_N) -g3 -fsanitize=address
			make fclean -C libft

$(OBONUS_O):$(BONUS_S)
			$(CC) -c $(CFLAGS) $(BONUS_S)

bonus:		$(BONUS_N)

.PHONY: 	all clean fclean re