/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlix_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:01:52 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 12:14:48 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLIX_BONUS_H
# define MLIX_BONUS_H

# include "../Libft/libft.h"
# include "../X11/X.h"
# include "../X11/keysym.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILESIZE 60
# define COLLECTIBLE "assets/collectible.xpm"
# define SOL "assets/sol.xpm"
# define EXIT "assets/exit.xpm"
# define WALL "assets/wall.xpm"
# define PLAYER_DOWN "assets/player_down.xpm"
# define PLAYER_LEFT "assets/player_left.xpm"
# define PLAYER_RIGHT "assets/player_right.xpm"
# define PLAYER_UP "assets/player_up.xpm"

# define ERROR "Error\n"

# include <stdint.h>

// with keysym of X11
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_imgs
{
	void		*ptr;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
	char		*data;
}				t_imgs;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_count
{
	int			total_p;
	int			total_c;
	int			total_e;
}				t_count;

typedef struct s_collect
{
	int			collect_count_c;
	int			collect_count_e;
}				t_collect;

typedef struct mlix
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_imgs		col;
	t_imgs		exit;
	t_imgs		sol;
	t_imgs		wall;
	t_imgs		player;
	t_imgs		monster;
	t_imgs		img_main;
	t_map		map;
	t_pos		pos_player;
	t_pos		new_pos_player;
	t_count		count_check;
	t_collect	collect;
	int			moves;
}				t_mlix;

// file of clean_bonus.c
void			free_map(t_map *map);
void			xpm_to_mlx_image2_for_destroy(t_mlix *mlx, t_imgs *img);
void			xpm_to_mlx_image1_for_destroy(t_mlix *mlx);
void			ft_clean(t_mlix *mlx, int index, char *msg);

// file of init_bonus.c
void			init_vars(t_mlix *mlx);
void			ft_init_mlx(t_mlix *mlx);

// file of draw_utils_bonus.c
void			xpm_to_mlx_image(t_mlix *mlx, char *path, t_imgs *img);
void			initialize_xpm_to_mlx_image(t_mlix *mlx);

// file of map_bonus.c
char			*check_end_of_line(char *line, int fd);
void			create_grid(t_mlix *mlx, char *line, int i, int line_width);
void			get_map_dimensions(t_mlix *mlx, const char *file_path);

// files of checks_bonus.c
void			check_all_conditions(t_mlix *mlx);
void			check_each_elements(t_mlix *mlx);
void			is_valid_borders(t_mlix *mlx);

// file of flood_fill_bonus.c
char			**seen(t_mlix *mlx);
void			flood_fill(t_mlix *mlx, int j, int i, char **c);
void			call_flood_fill(t_mlix *mlx);
void			behavior_of_flood_fill(t_mlix *mlx);

// file of draw_bonus.c
void			fill_main_image_with_differents_tiles(t_imgs *img_dst,
					t_mlix *mlx);
void			copy_pixel_to_image(t_mlix *mlx, t_imgs *img_src, int x_start,
					int y_start);
void			my_mlx_pixel_put(t_imgs *img, int x, int y, int color);

// file of move_of_player_bonus.c
void			player_movements(t_mlix *mlx, int new_y, int new_x);
void			render_map(t_mlix *mlx);
void			display_moves_on_screen(t_mlix *mlx);

#endif