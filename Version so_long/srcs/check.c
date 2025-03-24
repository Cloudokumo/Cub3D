/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:35:49 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 11:17:31 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlix.h"

void	check_all_conditions(t_mlix *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (mlx->map.grid[j])
	{
		i = 0;
		while (mlx->map.grid[j][i])
		{
			if (!ft_strchr("10CPE", mlx->map.grid[j][i]))
				ft_clean(mlx, 0, "Other characters than 1 0 p e c were found");
			i++;
		}
		j++;
	}
}

void	check_each_elements(t_mlix *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (mlx->map.grid[j])
	{
		i = 0;
		while (mlx->map.grid[j][i])
		{
			if (mlx->map.grid[j][i] == 'P')
				mlx->count_check.total_p = mlx->count_check.total_p + 1;
			else if (mlx->map.grid[j][i] == 'E')
				mlx->count_check.total_e = mlx->count_check.total_e + 1;
			else if (mlx->map.grid[j][i] == 'C')
				mlx->count_check.total_c = mlx->count_check.total_c + 1;
			i++;
		}
		j++;
	}
	if (mlx->count_check.total_p != 1 || mlx->count_check.total_e != 1
		|| mlx->count_check.total_c < 1)
		ft_clean(mlx, 0, "Invalid number of players, exits, or collectibles");
}

void	is_valid_borders(t_mlix *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.width)
	{
		if (mlx->map.grid[0][i] != '1')
			ft_clean(mlx, 0, "Map edges are invalid.");
		else if (mlx->map.grid[mlx->map.height - 1][i] != '1')
			ft_clean(mlx, 0, "Map edges are invalid.");
		i++;
	}
	i = 0;
	while (i < mlx->map.height)
	{
		if (mlx->map.grid[i][0] != '1')
			ft_clean(mlx, 0, "Map edges are invalid.");
		else if (mlx->map.grid[i][mlx->map.width - 1] != '1')
			ft_clean(mlx, 0, "Map edges are invalid.");
		i++;
	}
}
