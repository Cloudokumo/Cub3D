#include "cub3d.h"

void free_map(t_map *maps)
{
	int i;

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

void cleanup_map(t_map *map)
{
	// int i;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	// if (map->floor_color)
	// {
	// 	free(map->floor_color);
	// 	map->floor_color = NULL;
	// }
	// if (map->ceiling_color)
	// {
	// 	free(map->ceiling_color);
	// 	map->ceiling_color = NULL;
	// }
	if (map->grid)
		free_map(map);
	// {
	// 	i = 0;
	// 	while (i < map->height)
	// 	{
	// 		if (map->grid[i])
	// 			free(map->grid[i]);
	// 		i++;
	// 	}
	// 	free(map->grid);
	// }

	if (map->is_empty_line)
		free(map->is_empty_line);
}

void ft_clean_up(t_map *maps, int index, char *msg)
{
	// (void)maps;
	cleanup_map(maps);
	if (index == 1)
	{
		// ft_putstr_fd(msg, 2);
		// printf("%s\n", msg);
		// exit(EXIT_SUCCESS);
		// return;
		ft_putstr_fd("Error\n", 2);

		ft_putstr_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void cleanup_game(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx.mlx, game->textures[i].img);
		j++;
		i++;
	}
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
}
