/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:04:58 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:52:38 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_only_digits(char *str)
{
	if (!str || !*str)
	{
		ft_clean_up(NULL, 1, "Error\nColor must be numeric\n");
		return (0);
	}
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != ' ')
		{
			ft_clean_up(NULL, 1, "Error\nColor must be numeric\n");
			return (0);
		}
		str++;
	}
	return (1);
}

static int	validate_color_values(int values[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		if (!check_values(values[i]))
			return (ft_clean_up(NULL, 1, "Error\nColor values invalid\n"), 0);
	return (1);
}

static int	process_color_string(char *num_str, int values[3])
{
	char	*nbr;
	int		i;
	int		j;

	j = 0;
	nbr = get_color_values(num_str, 0);
	if (!is_only_digits(nbr))
		return (free(nbr), 0);
	values[0] = atoi(nbr);
	free(nbr);
	i = 0;
	while (++i <= 2)
	{
		while (num_str[j] != ',')
			j++;
		j++;
		nbr = get_color_values(num_str, j);
		if (!is_only_digits(nbr))
			return (free(nbr), 0);
		values[i] = atoi(nbr);
		free(nbr);
	}
	return (1);
}

int	parse_color(t_obj_reader *reader, t_color *color)
{
	int		values[3];
	char	*num_str;

	skip_whitespace(reader);
	num_str = read_string_map(reader);
	if (!num_str)
		return (0);
	if (count_commas(num_str) != 2)
	{
		free(num_str);
		return (ft_clean_up(NULL, 1, "Error\nColor must be in format R,G,B\n"),
			0);
	}
	if (!process_color_string(num_str, values))
	{
		free(num_str);
		return (0);
	}
	free(num_str);
	if (!validate_color_values(values))
		return (0);
	color->r = values[0];
	color->g = values[1];
	color->b = values[2];
	return (1);
}

void	free_duplicate_grid(char **grid, int height)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < height)
	{
		free(grid[i++]);
	}
	free(grid);
}
