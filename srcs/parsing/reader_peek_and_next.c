/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_peek_and_next.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:05:05 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:05:41 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_obj_reader	obj_create_reader(int fd, char *buffer, size_t buffer_size)
{
	t_obj_reader	reader;

	return ((t_obj_reader){.fd = fd, .buffer = buffer,
		.buffer_size = buffer_size, .len = 0, .i = 0, .column = 0, .line = 1});
	reader.fd = fd;
	reader.buffer = buffer;
	reader.buffer_size = buffer_size;
	reader.len = 0;
	reader.i = 0;
	reader.column = 0;
	reader.line = 1;
	return (reader);
}

int16_t	obj_reader_peek(t_obj_reader *self)
{
	size_t	len;

	if (self->i >= self->len)
	{
		len = read(self->fd, self->buffer, self->buffer_size);
		if (len <= 0)
			return (len);
		self->i = 0;
		self->len = len;
	}
	return (self->buffer[self->i]);
}

int	obj_reader_next(t_obj_reader *self)
{
	int16_t	c;

	c = obj_reader_peek(self);
	if (c == '\n')
	{
		self->line++;
		self->column = 0;
	}
	else if (c == -1)
		return (-1);
	else
		self->column++;
	self->i++;
	return (1);
}
