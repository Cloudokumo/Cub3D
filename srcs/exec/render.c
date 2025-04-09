#include "cub3d.h"

void raycasting(t_game *game, t_ray *ray)
{
    int x;
    double cam_x;

    game->player.plane_x = -game->player.dir_y * 0.6;
    game->player.plane_y = game->player.dir_x * 0.6;
    x = -1;
    while(++x < WIDTH)
    {
        cam_x = 2 * x / double(WIDTH) - 1;
        ray->ray_dir_x = game->player.dir_x + game->player.plane_x * cam_x;
        ray->ray_dir_y = game->player.dir_y + game->player.plane_y * cam_x;
    }

}

