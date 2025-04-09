#include "cub3d.h"

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx.mlx = mlx_init();

	if (!game->mlx.mlx)
		return (1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH,
			HEIGHT, "cub3D");
	if (!game->mlx.win)
		return (1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIDTH,
			HEIGHT);
	if (!game->mlx.img)
		return (1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
	init_player(game);
    if (load_textures(game) != 0)
    {
        return 1;
    }
    ft_memset(game->keys, 0, sizeof(game->keys));
	return (0);
}

void init_player(t_game *game)
{
    int x;
    int y;
    
    y = 0;

    while (game->map->grid[y])
    {
        x = 0;
        while (game->map->grid[y][x])
        {
            if (ft_strchr("NSEW", game->map->grid[y][x]))
            {
                game->player.pos_x = x + 0.5;
                game->player.pos_y = y + 0.5;
                if (game->map->grid[y][x] == 'N')
                {
                    game->player.dir_x = 0;
                    game->player.dir_y = -1;
                }
                else if (game->map->grid[y][x] == 'S')
                {
                    game->player.dir_x = 0;
                    game->player.dir_y = 1;
                }
                else if (game->map->grid[y][x] == 'E')
                {
                    game->player.dir_x = 1;
                    game->player.dir_y = 0;
                }
                else if (game->map->grid[y][x] == 'W')
                {
                    game->player.dir_x = -1;
                    game->player.dir_y = 0;
                }
                game->map->grid[y][x] = '0';
                return;
            }
            x++;
        }
        y++;
    }
}

int	load_textures(t_game *game)
{
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx.mlx,game->map->no, &game->textures[0].width, &game->textures[0].height);

	game->textures[1].img = mlx_xpm_file_to_image(game->mlx.mlx,
				game->map->so, &game->textures[1].width,
				&game->textures[1].height);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx.mlx,
				game->map->ea, &game->textures[2].width,
				&game->textures[2].height);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx.mlx,
				game->map->we, &game->textures[3].width,
				&game->textures[3].height);
    if (!game->textures[0].img || !game->textures[1].img|| !game->textures[2].img || !game->textures[3].img)
    {
        ft_putstr_fd("Texture loading failed \n", 2);
        return 1;
    }          
    game->textures[0].addr = mlx_get_data_addr(game->textures[0].img,
            &game->textures[0].bits_per_pixel, &game->textures[0].line_length,
            &game->textures[0].endian);
    game->textures[1].addr = mlx_get_data_addr(game->textures[1].img,
            &game->textures[1].bits_per_pixel, &game->textures[1].line_length,
            &game->textures[1].endian);
    game->textures[2].addr = mlx_get_data_addr(game->textures[2].img,
            &game->textures[2].bits_per_pixel, &game->textures[2].line_length,
            &game->textures[2].endian);
	game->textures[3].addr = mlx_get_data_addr(game->textures[3].img,
			&game->textures[3].bits_per_pixel, &game->textures[3].line_length,
			&game->textures[3].endian);
    if (!game->textures[0].addr  || !game->textures[1].addr  || !game->textures[2].addr 
                || !game->textures[3].addr)
    {
        ft_putstr_fd("Image loading failed :c\n", 2);
        return 1;
    }
	return (0);
}
