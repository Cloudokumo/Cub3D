#include "cub3d.h"

void	open_texture_file(t_game *game, int index)
{
	if (index == 0)
		get_size(game->map->no, game, index);
	if (index == 1)
		get_size(game->map->so, game, index);
	if (index == 2)
		get_size(game->map->ea, game, index);
	if (index == 3)
		get_size(game->map->we, game, index);
}

void	get_size(char *path, t_game *game, int index)
{
	int16_t			c;
	int				i;
	int				fd;
	char			*line;
	t_obj_reader	reader;
	char			buffer[BUFFER_SIZE];

	(void)game;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	reader = obj_create_reader(fd, buffer, BUFFER_SIZE);
	i = 0;
	line = NULL;
	while ((c = skip_whitespace_map(&reader)) != -1 && i < 4)
	{
		line = read_string_map(&reader);
		if (!line)
			break ;
		if (i == 3)
			get_height_width(game, line, index);
		i++;
	}
	close(fd);
}

void	get_height_width(t_game *game, char *line, int index)
{
	int		c;
	int		i;
	char	*nbr;
	int		j;
	int		u;

	i = 1;
	c = 0;
	j = 1;
	u = 0;
	while (c != 2)
	{
		while (line[i] != ' ')
			i++;
		i++;
		if (c == 1)
		{
			nbr = malloc((i - j) + 1);
			if (!nbr)
				return ;
			while (j < i)
				nbr[u++] = line[j++];
			nbr[u] = '\0';
			game->textures[index].height = atoi(nbr);
		}
		if (c == 2)
		{
			nbr = get_values(line, i);
			game->textures[index].width = atoi(nbr);
		}
	}
}

char	*get_values(char *line, int i)
{
	int		j;
	int		u;
	char	*nbr;

	j = i;
	u = 0;
	while (line[i] != ' ' && line[i])
		j++;
	nbr = malloc((i - j) + 1);
	if (!nbr)
		return (NULL);
	while (j < i)
		nbr[u++] = line[j++];
	nbr[u] = '\0';
	printf("%s nbr\n", line);
	return (nbr);
}
