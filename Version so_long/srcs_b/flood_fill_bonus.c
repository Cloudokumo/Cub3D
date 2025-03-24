/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:44:02 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 12:18:02 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

char	**seen(t_mlix *mlx)
{
	char	**tab;
	int		j;
	int		i;

	j = 0;
	tab = malloc(sizeof(char *) * (mlx->map.height + 1));
	if (!tab)
		ft_clean(mlx, 0, "Table height allocation failed");
	while (j < mlx->map.height)
	{
		tab[j] = malloc(sizeof(char) * (mlx->map.width + 1));
		if (!tab[j])
			ft_clean(mlx, 0, "Table width allocation failed");
		i = 0;
		while (i < mlx->map.width)
		{
			tab[j][i] = mlx->map.grid[j][i];
			i++;
		}
		tab[j][i] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

void	flood_fill(t_mlix *mlx, int j, int i, char **empty_tab)
{
	if (j < 0 || i < 0 || j >= mlx->map.height || i >= mlx->map.width
		|| empty_tab[j][i] == 'f' || mlx->map.grid[j][i] == '1')
		return ;
	if (mlx->map.grid[j][i] == 'C')
		mlx->collect.collect_count_c++;
	if (mlx->map.grid[j][i] == 'E')
	{
		mlx->collect.collect_count_e++;
		return ;
	}
	empty_tab[j][i] = 'f';
	flood_fill(mlx, j, i - 1, empty_tab);
	flood_fill(mlx, j, i + 1, empty_tab);
	flood_fill(mlx, j - 1, i, empty_tab);
	flood_fill(mlx, j + 1, i, empty_tab);
}

void	behavior_of_flood_fill(t_mlix *mlx)
{
	ft_printf("Number of collectibles collected on the map %d\n",
		mlx->collect.collect_count_c);
	ft_printf("Number of collectibles on the map %d\n",
		mlx->count_check.total_c);
	ft_printf("Number of exits on the map %d\n", mlx->count_check.total_e);
	if (mlx->collect.collect_count_c != mlx->count_check.total_c)
		ft_clean(mlx, 0, "There are still unattainable collectables!");
	if (mlx->collect.collect_count_e == 0)
		ft_clean(mlx, 0, "The exit is unattainable!");
	ft_printf("All collectables and release are accessible.\n");
}

void	call_flood_fill(t_mlix *mlx)
{
	char	**empty_tab;
	int		j;
	int		i;

	j = 0;
	empty_tab = seen(mlx);
	while (mlx->map.grid[j])
	{
		i = 0;
		while (mlx->map.grid[j][i])
		{
			if (mlx->map.grid[j][i] == 'P')
				flood_fill(mlx, j, i, empty_tab);
			i++;
		}
		j++;
	}
	j = 0;
	while (empty_tab[j])
		free(empty_tab[j++]);
	free(empty_tab);
	behavior_of_flood_fill(mlx);
}
