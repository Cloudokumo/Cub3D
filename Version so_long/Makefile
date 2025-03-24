# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:26:57 by carzhang          #+#    #+#              #
#    Updated: 2024/10/16 11:17:58 by carzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_b

INCLUDE = includes/mlix.h
INCLUDE_B = includes_b/mlix_bonus.h

ifeq ($(shell uname), Linux)
	CC = gcc
else
	CC = clang
endif

CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	MLX_INCLUDES = -I/usr/include -Imlx
else
	MLX_INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx_$(shell uname).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext -framework OpenGL \
	-framework AppKit
endif

SRCS_DIR = srcs
SRCS = so_long.c clean.c draw.c map.c draw_utils.c check.c flood_fill.c \
		move_of_player.c init.c

SRCS_DIR_B = srcs_b
SRCS_B = so_long_bonus.c check_bonus.c clean_bonus.c draw_bonus.c \
		draw_utils_bonus.c flood_fill_bonus.c init_bonus.c map_bonus.c \
		move_of_player_bonus.c

OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_B = $(SRCS_B:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(OBJS_DIR) $(MLX) $(LIBFT) $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(NAME_B) : $(OBJS_B) $(INCLUDE_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(MLX_FLAGS) $(LIBFT) -o $(NAME_B)

$(MLX) :
	make -C $(MLX_DIR)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

$(OBJS_DIR)/%.o : $(SRCS_DIR_B)/%.c
	$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

bonus : $(MLX) $(LIBFT) $(NAME_B)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	if [ -d $(OBJS_DIR) ]; then rm -rf $(OBJS_DIR); fi

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
