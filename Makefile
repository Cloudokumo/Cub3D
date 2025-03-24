CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -O2 -Iminilibx-linux
LDFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm
NAME 	= Cube3d
### DIRECTORIES ################################################################

SRCS_DIR 	 = srcs
SRCS_CUB3D 	 = $(SRCS_DIR)/Cube3d
SRCS_PARSING = $(SRCS_DIR)/parsing

OBJS_DIR 	= objs
INCLUDES_DIR = includes
INCLUDES_DIRS = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

### SRC ########################################################################

SRCS	= $(wildcard $(SRCS_EXEC)/*.c) \
			  $(wildcard $(SRCS_PARSING)/*.c) \

### OBJS ###########################################################################

OBJS	= $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))

### LIBFT ###########################################################################

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

### MLX ###########################################################################

MLX_DIR = ./minilibx-linux
MLX_GIT = https://github.com/42Paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx.a

### RULES ######################################a#####################################

all : $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then git clone $(MLX_GIT) $(MLX_DIR); fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all re fclean clean