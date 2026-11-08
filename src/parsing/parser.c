//42-Header
#include "cub3d.h"

int	open_file(char *cub_name)
{
	int	fd;

	fd = open(cub_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	return (fd);
}

int	parser(char *cub_name, t_data *data)
{
	int	fd;

	fd = open_file(cub_name);
	if (fd == -1)
		return (1);

//...
	close(fd);
	return (0);
}
