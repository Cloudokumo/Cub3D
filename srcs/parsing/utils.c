/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:05:08 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:05:08 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_values(int value)
{
	if (value < 0 || value > 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	skip_whitespace(t_obj_reader *reader)
{
	int16_t	c;

	c = obj_reader_peek(reader);
	while (c != -1 && (c == ' ' || c == '\t' || c == '\n'))
	{
		obj_reader_next(reader);
		c = obj_reader_peek(reader);
	}
	return (c);
}

int	skip_whitespace_map(t_obj_reader *reader)
{
	int16_t	c;

	c = obj_reader_peek(reader);
	while (c != -1 && (c == '\t' || c == '\n'))
	{
		obj_reader_next(reader);
		c = obj_reader_peek(reader);
	}
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
		c = obj_reader_peek(reader);
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
		c = obj_reader_peek(reader);
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
