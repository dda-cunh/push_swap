.SILENT:
NAME		= 	push_swap

CC 			= 	clang

CFLAGS		= 	-Wall -Wextra -Werror

RM 			= 	rm -f

INC_PATH	=	inc/

SRC_PATH	=	src/

SRC_		= 	push_swap.c utils.c stack.c \
				stack_utils.c ops.c sort.c index_utils.c

SRC			=	$(addprefix $(SRC_PATH), $(SRC_))

OBJ 		= 	$(SRC_:%.c=%.o)

GREEN		= 	\033[0;32m

RESET		=	\033[0m

$(NAME):		$(OBJ)
				make -C inc/libft
				$(CC) $(OBJ) -Linc/libft -lft -o $(NAME) -g -fsanitize=address
				make fclean -C inc/libft
				make done

$(OBJ):	 		$(SRC)
				$(CC) -c $(CFLAGS) $(SRC)

all: 			$(NAME)

clean:	
				$(RM) $(OBJ) push_swap_bonus.o

fclean:			clean
				$(RM) $(NAME)

re:				fclean	all

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

.PHONY: 		all clean fclean re