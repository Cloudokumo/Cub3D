#include <stdint.h>
#include  <stdlib.h>
 #include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_obj_reader
{
    int        fd;
    char    *buffer;
    size_t    buffer_size;
    size_t    len;
    size_t    i;
    size_t    column;
    size_t    line;
}                t_obj_reader;

t_obj_reader    obj_create_reader(int fd, char *buffer, size_t buffer_size)
{
    return ((t_obj_reader){
        .fd = fd,
        .buffer = buffer,
        .buffer_size = buffer_size,
        .len = 0,
        .i = 0,
        .column = 0,
        .line = 1});
}

int16_t    obj_reader_peek(t_obj_reader *self)
{
    size_t    len;

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

int    obj_reader_next(t_obj_reader *self)
{
    int16_t    c;

    if ((c = obj_reader_peek(self)) == '\n')
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

/* int main(int argc, char **argv)
{
    (void)argc;
    int fd = open(argv[1], O_RDONLY);
    char buffer[4096];
    char c;
    t_obj_reader tetelecture;
    tetelecture = obj_create_reader(fd, buffer, 4096);
    while ((c = obj_reader_peek(&tetelecture)) != 0)
    {
		if (c == -1)
		{
			printf("error");
			return(0);
		}
        printf("%c", c);
        obj_reader_next(&tetelecture);
    }
} */