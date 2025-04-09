#include "cub3d.h"

char	**duplicate_grid(t_map *maps)
{
	char	**tab;
	int		j;
	int		i;
	int		line_len;

	j = 0;
	tab = malloc(sizeof(char *) * (maps->height + 1));
	if (!tab)
		ft_clean_up(maps, 0, "Table height allocation failed");
	while (j < maps->height)
	{
		line_len = ft_strlen(maps->grid[j]);
		tab[j] = malloc(sizeof(char) * (maps->width + 1));
		if (!tab[j])
			ft_clean_up(maps, 0, "Table width allocation failed");
		i = 0;
		while (i < line_len)
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

int	flood_fill(t_map *maps, int j, int i, char **new_grid)
{
	if (j < 0 || i < 0 || j >= maps->height || i >= maps->width)
		return (0);
	if (new_grid[j][i] == ' ' || new_grid[j][i] == '\t')
	{
		new_grid[j][i] = '1';
	}
	if (new_grid[j][i] == 'X' || new_grid[j][i] == '1')
		return (1);
	new_grid[j][i] = 'X';
	if (check_next_step(maps, j, i) && flood_fill(maps, j, i - 1, new_grid)
		&& flood_fill(maps, j, i + 1, new_grid) && flood_fill(maps, j - 1, i,
			new_grid) && flood_fill(maps, j + 1, i, new_grid))
		return (1);
	return (0);
}

int	check_next_step(t_map *maps, int y, int x)
{
	if (x <= 0 || y <= 0 || y + 1 >= maps->height || x + 1 >= maps->width)
		return (0);
	if (maps->grid[y][x + 1] && maps->grid[y][x - 1] && maps->grid[y + 1][x]
		&& maps->grid[y - 1][x])
		return (1);
	return (0);
}

// int flood_fill(t_map *maps, int j, int i, char **new_grid)
// {
// 	if (j < 0 || i < 0 || j >= maps->height || i >= maps->width )
// 		return (0);
// 	if (new_grid[j][i] && (new_grid[j][i] == 'X' || new_grid[j][i] == '1'))
// 		return (1);
// 	new_grid[j][i] = 'X';
// 	if (check_next_step(maps, j, i)
// 		&& (new_grid[j][i - 1] && flood_fill(maps, j, i - 1, new_grid) == 1)
// 		&& (new_grid[j][i + 1] && flood_fill(maps, j, i + 1, new_grid) == 1)
// 		&& (new_grid[j - 1][i] && flood_fill(maps, j - 1, i, new_grid) == 1)
// 		&& (new_grid[j + 1][i] && flood_fill(maps, j + 1, i, new_grid) == 1))
// 		return (1);
// 	else
// 		return (0);
// 	return (1);

// }

// int check_next_step(t_map *maps, int y, int x)
// {
// 	if ((maps->grid[y] && maps->grid[y][x + 1]) && (x != 0 && maps->grid[y][x- 1])
// 	&& (maps->grid[y + 1] && maps->grid[y + 1][0] && x <= ft_len(maps->grid[y+ 1]))
// 	&& (y != 0 && x <= ft_len(maps->grid[y - 1]) && maps->grid[y - 1][0]))
// 		return (1);
// 	return (0);
// }
void	call_flood_fill(t_map *maps)
{
	char	**new_grid;
	int		j;
	int		i;

	j = 0;
	new_grid = duplicate_grid(maps);
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (ft_strchr("NSWE", maps->grid[j][i]))
			{
				if (flood_fill(maps, j, i, new_grid))
					printf("Flood fill succeeded\n");
				else
					ft_clean_up(maps, 0, "Invalid map :missing walls");
			}
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
}
