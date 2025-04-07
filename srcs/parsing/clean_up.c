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

void ft_clean_up(t_map *maps, int index, char *msg)
{
	if (maps)
	{
		if (maps->grid)
			free_map(maps);
	}
	if (index == 1)
	{
		printf("%s\n", msg);
		exit(EXIT_SUCCESS);
	}
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}