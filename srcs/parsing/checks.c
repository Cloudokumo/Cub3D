#include "cub3d.h"

void	check_all_conditions(t_map *maps)
{
	int	i;
	int	j;

	j = 0;
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (!ft_strchr("10NSWE ", maps->grid[j][i]))
				ft_clean_up(maps, 3,
					"Error\nOther characters than 1,0,N,S,W,E,were found\n");
			i++;
		}
		j++;
	}
}

void	check_n_s_w_e_elements(t_map *maps)
{
	int	i;
	int	j;
	int	player_found;

	player_found = 0;
	j = 0;
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (player_found == 1 && ft_strchr("NSWE", maps->grid[j][i]))
				ft_clean_up(maps, 3, "Error\nDouble player found\n");
			else if (ft_strchr("NSWE", maps->grid[j][i]))
				player_found = 1;
			i++;
		}
		j++;
	}
	if (player_found == 0)
		ft_clean_up(maps, 3, "Error\nNo player found\n");
}
