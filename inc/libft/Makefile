NAME	= 	libft.a

CC 		= 	clang

AR		=	ar rcs

CFLAGS	= 	-c -Wall -Wextra -Werror

RM 		= 	rm -f

SRC		= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
			ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
			ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_striteri.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
			get_next_line_utils.c ft_sisnum.c ft_sisint.c

SRCB	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJ 	= 	$(SRC:%.c=%.o)

OBJB	=	$(SRCB:%.c=%.o)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

$(OBJ): 	$(SRC)
			$(CC) $(CFLAGS) $(SRC)

$(OBJB):	$(SRCB)
			$(CC) $(CFLAGS) $(SRCB)
			$(AR) $(NAME) $(OBJB)

all: 		$(NAME)

bonus:		$(OBJB)

clean:
			$(RM) $(OBJ) $(OBJB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

.PHONY: 	all clean fclean re
