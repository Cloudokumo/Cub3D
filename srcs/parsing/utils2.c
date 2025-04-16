/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:05:00 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:55:55 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_commas(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

char	*get_color_values(char *str, int j)
{
	int		i;
	int		u;
	char	*nbr;

	i = j;
	u = 0;
	while (str[j] != ',' && str[j])
		j++;
	nbr = malloc(sizeof(char) * (j - i) + 1);
	if (!nbr)
		return (NULL);
	while (i < j)
		nbr[u++] = str[i++];
	nbr[u] = '\0';
	return (nbr);
}

int	parse_color_element(t_obj_reader *reader, t_color *color, int *found)
{
	if (*found)
	{
		ft_clean_up(NULL, 1, "Error\nDuplicate color\n");
		return (0);
	}
	if (!parse_color(reader, color))
		return (0);
	*found = 1;
	return (1);
}

int	check_next_step(t_map *maps, int y, int x)
{
	if (!is_safe_to_check_neighbors(maps, y, x))
		return (0);
	if (maps->grid[y][x + 1] != '\0' && maps->grid[y][x - 1] != '\0'
		&& maps->grid[y + 1][x] != '\0' && maps->grid[y - 1][x] != '\0')
		return (1);
	return (0);
}
