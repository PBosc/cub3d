CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
INCLUDE = -I./includes -Iminilibx-linux
VPATH = srcs srcs/parsing srcs/utils srcs/error srcs/get_next_line srcs/ft_dprintf srcs/raycasting
RM = rm -rvf
NAME = cub3D

UTILS = utils1 utils2 utils3 utils4 ft_split
PARSING = checkings colors init map textures format
ERROR = panic garbage
GNL = get_next_line get_next_line_utils
DPRINTF = ft_dprintf dprintf_utils dprintf_utils2
RAYCASTING = draw hooks init_ray moves raycasting utils handle_doors rotations texture

SRCS = $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(PARSING))\
	   $(addsuffix .c, $(ERROR))\
	   $(addsuffix .c, $(GNL))\
	   $(addsuffix .c, $(DPRINTF))\
	   $(addsuffix .c, $(RAYCASTING))\
	   main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: all

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c includes/cub.h includes/ft_dprintf.h includes/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus