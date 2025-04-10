CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -O2 -Iminilibx-linux -gdwarf-4
LDFLAGS	= -Lminilibx-linux -lmlx -LLibft -lft -lXext -lX11 -lm
NAME 	= Cub3d

### DIRECTORIES ################################################################

SRCS_DIR 	 = srcs
SRCS_CUB3D 	 = $(SRCS_DIR)/cub3d
SRCS_PARSING = $(SRCS_DIR)/parsing
SRCS_EXEC    = $(SRCS_DIR)/exec

OBJS_DIR 	= objs
INCLUDES_DIR = includes
INCLUDES_DIRS = -I$(INCLUDES_DIR)

### SRC ########################################################################

SRCS	=	$(wildcard $(SRCS_CUB3D)/*.c) \
			$(wildcard $(SRCS_PARSING)/*.c) \
			$(wildcard $(SRCS_EXEC)/*.c)

### OBJS ###########################################################################

OBJS	= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

### MLX ###########################################################################

MLX_DIR = ./minilibx-linux
MLX_GIT = https://github.com/42Paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx.a

### RULES ######################################a#####################################

all : $(MLX) $(NAME)

$(NAME): $(OBJS) $(MLX)
	@$(MAKE) -C ./Libft
	@$(CC) $(OBJS) $(MLX) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_DIRS) -c $< -o $@

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then git clone $(MLX_GIT) $(MLX_DIR); fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@if [ -d $(MLX_DIR) ]; then $(MAKE) -C $(MLX_DIR) clean; fi
	@$(MAKE) -C ./Libft clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C ./Libft fclean

re : fclean all

.PHONY : all re fclean clean