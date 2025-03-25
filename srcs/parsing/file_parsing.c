#include "cub3d.h"

char	*check_end_of_line(char *line, int fd)
{
	while (line = get_next_line(fd));
	{
        if (!line)
		    return (NULL);
	    if (line[ft_strlen(line) - 1] == '\n')
		    line[ft_strlen(line) - 1] = '\0';
    }
	return (line);
}

int read_file(char *line, int fd)
{
    line = check_end_of_line(line, fd);
    if (!line)
       printf("file is empty");
    while (line = get_next_line(fd))
    {
        if (is_map(line) != 0)
        {
            get_texture(line);
            get_color(line);
        }
    }
}

int is_map(char *line)
{
    if (ft_strncmp(line, "NO", 2) == 0)
        return (1);
    if (ft_strncmp(line, "SO", 2) == 0)
        return (1);
    if (ft_strncmp(line, "EA", 2) == 0)
        return (1);
    if (ft_strncmp(line, "WE", 2) == 0)
        return (1);
    if (line[0] == 'C' && line[0] == 'F')
        return (1);
    else
        return (0);
}

int check_map_file(const char *file_path)
{
	int	fd;
    int i;
	char *line;

    line = NULL;
    i = 0;
    if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 4) != 0)
        printf("Wrong file extension\n");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
    {
        printf("No file found");
        return (EXIT_FAILURE);
    }
    read_file(line, fd);
}

    // tab['NO', 'SO', 'WE', 'EA'] = {0, 0, 0, 0};

    // if (NO)
    //     while (line[i] == ' ')
    //         i++;
    //     tab = [SO, WE, EA]  
    //     return 0
    // if (NO)
    //     tab = [SO, WE, EA]  
    //     return 0
    // if (NO)
    //     tab = [SO, WE, EA]  
    //     return 0
    // if (NO)
    //     tab = [SO, WE, EA]  
    //     return 0
    // else 
    //     return 1;
