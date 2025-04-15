#include "cub3d.h"

int	skip_whitespace(t_obj_reader *reader)
{
	int16_t	c;

	c = obj_reader_peek(reader);
	while (c != -1 && (c == ' ' || c == '\t' || c == '\n'))
		obj_reader_next(reader);
	return (c);
}

int	skip_whitespace_map(t_obj_reader *reader)
{
	int16_t	c;

	c = obj_reader_peek(reader);
	while (c != -1 && (c == '\t' || c == '\n'))
		obj_reader_next(reader);
	return (c);
}

char	*read_string(t_obj_reader *reader)
{
	char	*str;
	size_t	len;
	int16_t	c;
	char	temp[1024];

	str = NULL;
	len = 0;
	skip_whitespace(reader);
	c = obj_reader_peek(reader);
	while (c != -1 && c != ' ' && c != '\n' && c != '\t' && c != '\0')
	{
		if (len < sizeof(temp) - 1)
			temp[len++] = c;
		obj_reader_next(reader);
	}
	if (len == 0)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	memcpy(str, temp, len);
	str[len] = '\0';
	return (str);
}

char	*read_string_map(t_obj_reader *reader)
{
	char	*str;
	size_t	len;
	int16_t	c;
	char	temp[1024];

	str = NULL;
	len = 0;
	skip_whitespace_map(reader);
	c = obj_reader_peek(reader);
	while (c != -1 && c != '\n' && c != '\t')
	{
		if (len < sizeof(temp) - 1)
			temp[len++] = c;
		obj_reader_next(reader);
		if (c == '\0')
			break ;
	}
	if (len == 0)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, temp, len);
	str[len] = '\0';
	return (str);
}
