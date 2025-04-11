#include "cub3d.h"

int	game_loop(t_game *game)
{
	t_ray	ray;

	handle_movement(game);
    if (game->mlx.img)
    {        
        raycasting(game, &ray);
	    mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
    }
    return (0);
}

int	mouse(int x, int y, void *arg)
{
	static int	old_x = 0;
	t_game		*game;

	(void)y;
	game = (t_game *)arg;
	if (!old_x)
		old_x = x;
	if (old_x < x)
		rotate_right(game, MOUSE_SPEED);
	if (old_x > x)
		rotate_left(game, MOUSE_SPEED);
	old_x = x;
	return (0);
}

int	run_game(t_game *game)
{
	mlx_hook(game->mlx.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx.win, 17, 0, close_window, game);
	mlx_hook(game->mlx.win, MotionNotify, PointerMotionMask, &mouse, game);
	mlx_loop_hook(game->mlx.mlx, game_loop, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	maps;
	t_game	game;

	if (ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	ft_memset(&maps, 0, sizeof(maps));
	ft_memset(&game, 0, sizeof(t_game));
	if (check_map_file(&maps, av) != 1)
		return (1);
	if (init_game(&game, &maps) != 0)
		return (1);
	run_game(&game);
	cleanup_game(&game);
	cleanup_map(&maps);
	return (0);
}
