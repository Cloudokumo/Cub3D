#include "cub3d.h"

char **duplicate_grid(t_map *maps)
{
	char **tab;
	int j;
	int i;

	j = 0;
	tab = malloc(sizeof(char *) * (maps->height + 1));
	if (!tab)
		printf("Table height allocation failed");
	while (j < maps->height)
	{
		tab[j] = malloc(sizeof(char) * (maps->width + 1));
		if (!tab[j])
			printf("Table width allocation failed");
		i = 0;
		while (i < maps->width)
		{
			tab[j][i] = maps->grid[j][i];
			i++;
		}
		tab[j][i] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

void	flood_fill(t_map *maps, int j, int i, char **empty_tab)
{
	if (j < 0 || i < 0 || j >= maps->height || i >= maps->width || empty_tab[j][i] == 'X' || maps->grid[j][i] == '1')
		return ;

	empty_tab[j][i] = 'X';
	flood_fill(maps, j, i - 1, empty_tab);
	flood_fill(maps, j, i + 1, empty_tab);
	flood_fill(maps, j - 1, i, empty_tab);
	flood_fill(maps, j + 1, i, empty_tab);
}

void call_flood_fill(t_map *maps)
{
	char **new_grid;
	int j;
	int i;

	j = 0;
	new_grid = duplicate_grid(maps);
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (/* maps->grid[j][i] == 'P' */ ft_strchr("NSWE", maps->grid[j][i]))
				flood_fill(maps, j, i, new_grid);

			i++;
		}
		j++;
	}
	i = 0;
	while (i < maps->height)
	{
		printf("[%d] : %s\n", i, new_grid[i]);
		i++;
	}
	j = 0;
	while (new_grid[j])
		free(new_grid[j++]);
	free(new_grid);
	printf("Flood fill completed\n");
	// behavior_of_flood_fill(maps);
}