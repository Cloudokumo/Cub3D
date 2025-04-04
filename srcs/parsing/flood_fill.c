#include "cub3d.h"

int ft_len(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
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

int flood_fill(t_map *maps, int j, int i, char **empty_tab)
{
	if (j < 0 || i < 0 || j >= maps->height || i >= maps->width )
		return (1);
	if (empty_tab[j][i] && (empty_tab[j][i] == 'X' || empty_tab[j][i] == '1'))
		return (0);
	empty_tab[j][i] = 'X';
	if (!check_next_step(maps, j, i)
		&& (empty_tab[j][i - 1] && flood_fill(maps, j, i - 1, empty_tab) == 0)
		&& (empty_tab[j][i + 1] && flood_fill(maps, j, i + 1, empty_tab) == 0)
		&& (empty_tab[j - 1][i] && flood_fill(maps, j - 1, i, empty_tab) == 0 )
		&& (empty_tab[j + 1][i] &&flood_fill(maps, j + 1, i, empty_tab) == 0))
		{
			return (0);
		}
	else
		return (1);
	return (0);
}

int check_next_step(t_map *maps, int y, int x)
{
	if ((maps->grid[y] && maps->grid[y][x + 1]) && (x != 0 && maps->grid[y][x - 1]) && (maps->grid[y + 1] && maps->grid[y + 1][0] && x <= ft_len(maps->grid[y + 1])) && (y != 0 && x <= ft_len(maps->grid[y - 1]) && maps->grid[y - 1][0]))
		return (0);
	return (1);
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
				if (flood_fill(maps, j, i, new_grid))
					printf("Flood fill failed\n");
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