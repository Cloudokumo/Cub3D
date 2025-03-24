#include "cub3d.h"
int check_map_file(const char *file_path)
{
	int	fd;
	char *line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("No file found");
	
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
