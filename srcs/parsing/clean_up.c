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

void	cleanup_map(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	if (map->grid)
		free_map(map);
	if (map->is_empty_line)
		free(map->is_empty_line);
}

void	ft_clean_up(t_map *maps, int index, char *msg)
{
	if (index == 1)
		ft_putstr_fd(msg, 2);
	if (index == 2)
	{
		cleanup_map(maps);
		exit(EXIT_FAILURE);
	}
	if (index == 3)
	{
		ft_putstr_fd(msg, 2);
		cleanup_map(maps);
		exit(EXIT_FAILURE);
	}
}

void	cleanup_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx.mlx, game->textures[i].img);
		i++;
	}
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
		mlx_destroy_display(game->mlx.mlx);
}
