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
