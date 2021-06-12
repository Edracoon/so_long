NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS =	srcs/main.c \
		srcs/init_map_ber.c \
		srcs/stockage_map.c \
		srcs/mlx_main.c \
		srcs/mouvement.c \
		srcs/key_pressed.c \
		srcs/utils.c \
		srcs/map_case.c \
		srcs/print_map_char.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all:		libft $(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) $(OBJS) ./libft/libft.a -lmlx -framework OpenGL -framework Appkit -o $(NAME)

libft:
			make -C ./libft

clean:
			rm -f $(OBJS)
			#make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

norme:
			norminette $(SRCS)

re:			fclean all

.PHONY:		re clean fclean all libft