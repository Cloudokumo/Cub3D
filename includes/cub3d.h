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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_map
{
    char    dir_name;
    char	*no;
	char	*so;
	char	*we;
	char	*ea;
    t_color	floor_color;
	t_color	ceiling_color;
    
}               t_map;




#endif