#include "cub3d.h"

void	free_map(t_map *maps)
{
	int	i;

	i = 0;
	while (i < maps->height)
	{
		free(maps->grid[i]);
		maps->grid[i] = NULL;
		i++;
	}
	free(maps->grid);
	maps->grid = NULL;
}

void	ft_clean_up(t_map *maps, int index, char *msg)
{
	// if (maps)
	// {
	// 	if (maps->grid)
	// 		free_map(maps);
	// }
    (void)maps;
	if (index == 1)
	{
		printf("%s\n", msg);
		return ;
	}
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	cleanup_game(t_game *game)
{
	int	i;
    int j;

    i = 0;
    j = -1;
	while (++j < 4)
	{
		if (game->textures[i].img)
		{
			mlx_destroy_image(game->mlx.mlx, game->textures[i].img);
			game->textures[i++].img = NULL;
		}
	}
	if (game->mlx.img)
	{
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
		game->mlx.img = NULL;
	}
	if (game->mlx.win)
	{
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		game->mlx.win = NULL;
	}
}

void	cleanup_map(t_map *map)
{
	int i;

	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->is_empty_line)
		free(map->is_empty_line);
}