#include "cub3d.h"

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
