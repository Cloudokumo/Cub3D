#include "cub3d.h"

char	*check_end_of_line(char *line, int fd)
{
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

int check_map_file(const char *file_path)
{
	int	fd;
    int i;
	char *line;

    line = NULL;
    i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("No file found");
    line = check_end_of_line(line, fd);
    if (!line)
       printf("file is empty");
    while (i != 4)
    {
        while 
    }
}

int directions_setup(int fd)
{
    char **tab

    tab = [NO, SO, WE, EA]
    if (NO)
        while (' ')

        tab = [SO, WE, EA]  
        return 0
    if (NO)
        tab = [SO, WE, EA]  
        return 0
    if (NO)
        tab = [SO, WE, EA]  
        return 0
    if (NO)
        tab = [SO, WE, EA]  
        return 0
    else 
        return 1;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
   	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
        printf("Wrong file extension\n");
	
    return (0);
}
