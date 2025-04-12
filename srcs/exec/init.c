#include "cub3d.h"

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->mlx.win)
		return (1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (!game->mlx.img)
		return (1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
	init_player(game);
	if (load_textures(game) != 0)
	{
		return (1);
	}
	init_keys(game);
	return (0);
}

void	init_keys(t_game *game)
{
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
}

static void	init_the_player(t_game *game, int x, int y)
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
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (ft_strchr("NSEW", game->map->grid[y][x]))
			{
				init_the_player(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}
