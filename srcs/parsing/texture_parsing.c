/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:04:33 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:05:08 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_texture_path(const char *path)
{
	int	fd;
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(path + len - 4, ".xpm") != 0)
	{
		ft_clean_up(NULL, 1, "Error\nTexture file must have .xpm extension\n");
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_clean_up(NULL, 1, "Error\nCannot open texture file\n");
		return (0);
	}
	close(fd);
	return (1);
}

static int	parse_texture(t_obj_reader *reader, char **texture_ptr, int *found)
{
	if (*found)
	{
		ft_clean_up(NULL, 1, "Error\nDuplicate texture\n");
		return (0);
	}
	*texture_ptr = read_string(reader);
	if (!*texture_ptr)
		return (0);
	if (!is_valid_texture_path(*texture_ptr))
	{
		free(*texture_ptr);
		*texture_ptr = NULL;
		return (0);
	}
	*found = 1;
	return (1);
}

static int	process_element(t_obj_reader *reader, t_map *map, char *type,
		int found[6])
{
	if (strcmp(type, "NO") == 0)
		return (parse_texture(reader, &map->no, &found[0]));
	else if (strcmp(type, "SO") == 0)
		return (parse_texture(reader, &map->so, &found[1]));
	else if (strcmp(type, "WE") == 0)
		return (parse_texture(reader, &map->we, &found[2]));
	else if (strcmp(type, "EA") == 0)
		return (parse_texture(reader, &map->ea, &found[3]));
	else if (strcmp(type, "F") == 0)
		return (parse_color_element(reader, &map->floor_color, &found[4]));
	else if (strcmp(type, "C") == 0)
		return (parse_color_element(reader, &map->ceiling_color, &found[5]));
	else
	{
		ft_clean_up(NULL, 1, "Error\nUnknown map element\n");
		return (0);
	}
	return (0);
}

static int	check_completion(int found[6])
{
	int	complete;

	complete = 1;
	if (!found[0])
		complete = 0;
	if (!found[1])
		complete = 0;
	if (!found[2])
		complete = 0;
	if (!found[3])
		complete = 0;
	if (!found[4])
		complete = 0;
	if (!found[5])
		complete = 0;
	if (complete)
		return (1);
	return (0);
}

int	parse_map_config(t_obj_reader *reader, t_map *map)
{
	int16_t	c;
	char	*type;
	int		found[6];

	ft_memset(found, 0, sizeof(found));
	c = skip_whitespace(reader);
	while (c != -1)
	{
		type = read_string(reader);
		if (!type)
			break ;
		if (!process_element(reader, map, type, found))
			return (free(type), 0);
		free(type);
		if (check_completion(found))
			return (1);
		c = skip_whitespace(reader);
	}
	if (!check_completion(found))
	{
		ft_clean_up(NULL, 1, "Error\nMissing required map elements\n");
		return (0);
	}
	return (1);
}
