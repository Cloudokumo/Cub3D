/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:50:45 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 14:08:22 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**duplicate_grid(t_map *maps)
{
	char	**tab;
	int		j;
	int		i;
	int		line_len;

	j = -1;
	tab = malloc(sizeof(char *) * (maps->height + 1));
	if (!tab)
		ft_clean_up(maps, 3, "Error\nTable height allocation failed\n");
	while (++j < maps->height)
	{
		line_len = ft_strlen(maps->grid[j]);
		tab[j] = malloc(sizeof(char) * (maps->width + 1));
		if (!tab[j])
			ft_clean_up(maps, 3, "Error\nTable width allocation failed\n");
		i = -1;
		while (++i < line_len)
			tab[j][i] = maps->grid[j][i];
		tab[j][i] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

static int	is_within_bounds(t_map *maps, int y, int x)
{
	if (y < 0 || x < 0 || y >= maps->height || x >= maps->width)
		return (0);
	if (x >= (int)ft_strlen(maps->grid[y]))
		return (0);
	return (1);
}

int	is_safe_to_check_neighbors(t_map *maps, int y, int x)
{
	if (y <= 0 || x <= 0 || y + 1 >= maps->height || x + 1 >= maps->width)
		return (0);
	if (x >= (int)ft_strlen(maps->grid[y - 1])
		|| x >= (int)ft_strlen(maps->grid[y + 1]))
		return (0);
	return (1);
}

int	flood_fill(t_map *maps, int j, int i, char **new_grid)
{
	int	result;

	if (!is_within_bounds(maps, j, i) || i >= (int)ft_strlen(new_grid[j]))
		return (0);
	if (new_grid[j][i] == ' ' || new_grid[j][i] == '\t')
	{
		new_grid[j][i] = '1';
		maps->grid[j][i] = '1';
	}
	if (new_grid[j][i] == 'X' || new_grid[j][i] == '1')
		return (1);
	new_grid[j][i] = 'X';
	if (!is_safe_to_check_neighbors(maps, j, i) || !check_next_step(maps, j, i))
		return (0);
	result = flood_fill_neighbors(maps, j, i, new_grid);
	return (result);
}

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
				if (!flood_fill(maps, j, i, new_grid))
				{
					free_duplicate_grid(new_grid, maps->height);
					ft_clean_up(maps, 3,
						"Erreur\nInvalid map :missing walls\n");
				}
			}
			i++;
		}
		j++;
	}
	free_duplicate_grid(new_grid, maps->height);
}
