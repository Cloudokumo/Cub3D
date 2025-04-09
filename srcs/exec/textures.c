#include "cub3d.h"

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char *dst;
    
    if (x < 0 || y < 0 || x >= mlx->win_width || y >= mlx->win_height)
        return;
    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void draw_ceiling_floor(t_game *game)
{
    int x;
    int y;
    int color;
    
    color = (game->map->ceiling_color.r << 16) | 
            (game->map->ceiling_color.g << 8) | 
            (game->map->ceiling_color.b);
    y = 0;
    while (y < game->mlx.win_height / 2)
    {
        x = 0;
        while (x < game->mlx.win_width)
        {
            my_mlx_pixel_put(&game->mlx, x, y, color);
            x++;
        }
        y++;
    }
    color = (game->map->floor_color.r << 16) | 
            (game->map->floor_color.g << 8) | 
            (game->map->floor_color.b);
    y = game->mlx.win_height / 2;
    while (y < game->mlx.win_height)
    {
        x = 0;
        while (x < game->mlx.win_width)
        {
            my_mlx_pixel_put(&game->mlx, x, y, color);
            x++;
        }
        y++;
    }
}
