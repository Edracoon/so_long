NAME = so_long

CFLAGS = -Wall -Wextra -Werror

LIB_DIR = /usr/local/include

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

all:		libft $(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) ./libft/libft.a -I $(LIB_DIR) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

libft:
			make -C ./libft

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft