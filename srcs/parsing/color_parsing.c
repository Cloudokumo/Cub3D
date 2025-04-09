#include "cub3d.h"

int	parse_color(t_obj_reader *reader, t_color *color)
{
	int		values[3];
	char	*num_str;
	int		i;
	int		j;
	char	*nbr;

	j = 0;
	i = 0;
	skip_whitespace(reader);
	num_str = read_string_map(reader);
	if (!num_str)
		return (0);
	values[0] = atoi(num_str);
	while (++i <= 2)
	{
		while (num_str[j] != ',')
			j++;
		j++;
		nbr = get_color_values(num_str, j);
		values[i] = atoi(nbr);
	}
	free(num_str);
	i = 0;
	while (i < 3)
	{
		if (!check_values(values[i]))
		{
			printf("wrong color values\n");
			return (0);
		}
		i++;
	}
	color->r = values[0];
	color->g = values[1];
	color->b = values[2];
	return (1);
}

int	check_values(int value)
{
	if (value < 0 || value > 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
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
	nbr = malloc((j - i) + 1);
	if (!nbr)
		return (NULL);
	while (i < j)
		nbr[u++] = str[i++];
	nbr[u] = '\0';
	printf("%s nbr\n", nbr);
	return (nbr);
}

int	parse_color_element(t_obj_reader *reader, t_color *color, int *found)
{
	if (*found)
	{
		printf("Error: Duplicate color\n");
		return (0);
	}
	if (!parse_color(reader, color))
		return (0);
	*found = 1;
	return (1);
}
