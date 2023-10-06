NAME = cub3D

SRCS = src/main.c \
	   src/ft_memory_cleaner2000.c \
	   src/game_checker.c \
	   src/game_init.c \
	   src/game_init_utils.c \
	   src/game_color.c \
	   src/game_flood_filling.c \
	   src/game_manager.c \
	   src/game_manager_utils.c \
	   src/game_parser.c \
	   src/game_parser_utils.c \
	   src/game_parser_utils2.c \
	   src/game_parser_utils3.c \
	   src/game_player_ctrl.c \
	   src/game_player_ctrl_utils.c \
	   src/game_render_square_builder.c \
	   src/game_render_square_builder_utils.c \
	   src/game_sprite.c \
	   src/game_sprite_utils.c \
	   src/game_render_utils.c \
	   src/game_render_utils2.c \
	   src/game_render_utils3.c \
	   src/game_render.c \
	   src/game_utils.c \
	   src/game_error.c \
	   src/game_screenshot.c \
	   gnl/src/get_next_line.c \
	   gnl/src/get_next_line_utils.c 


CFLAGS = -g -O3 -Wno-implicit-function-declaration

OBJS = $(SRCS:.c=.o)

all : gnl libft minilibx $(NAME)

gnl :
	make -C gnl/

libft :
	make -C libft/

minilibx :
	make -C minilibx/

$(%.o): $(%.c)
	gcc $(CFLAGS) -o $@ -c $^

$(OBJS) : gnl/includes/get_next_line.h libft/includes/libft.h minilibx/mlx.h includes/cub3d.h

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^ -L minilibx -lmlx -L libft -lft

clean :
	rm -f $(OBJS)
	make -C gnl/ clean
	make -C libft/ clean
	make -C minilibx/ clean

fclean : clean
	rm -f $(NAME)
	make -C gnl/ fclean
	make -C libft/ fclean
	make -C minilibx/ clean

re : fclean all

.PHONY: all clean fclean re libft minilibx gnl