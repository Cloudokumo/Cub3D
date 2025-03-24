#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
// # include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

typedef struct s_colors
{
    char    name;
    int     R;
    int     G;
    int     B;
}               t_colors;

typedef struct s_directions
{
    char    dir_name;
    char    *texture_path;
}               t_directions;


#endif