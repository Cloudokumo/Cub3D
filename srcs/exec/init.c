#include "cub3d.h"

int init_game(t_game *game, t_map *map)
{
    game->map = map;
    game->mlx.mlx = mlx_init();
    if (!game->mlx.mlx)
        return (1);
    game->mlx.win_width = 1280;
    game->mlx.win_height = 720;
    game->mlx.win = mlx_new_window(game->mlx.mlx, game->mlx.win_width, 
                                    game->mlx.win_height, "cub3D");
    if (!game->mlx.mlx)
        return (1);
    game->mlx.img = mlx_new_image(game->mlx.mlx, game->mlx.win_width, 
                                             game->mlx.win_height);
    if (!game->mlx.img)
        return (1);
    game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
                                    &game->mlx.line_length, &game->mlx.endian);
    init_player(game);

}

void init_player(t_game *game)
{
    int x;
    int y;

    y = 0;
    
}