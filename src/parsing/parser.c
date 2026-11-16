//42-Header
#include "cub3d.h"

/**
 * Open the file with the given name and return its file descriptor
 * @param cub_name The name of the file to open
 * @return The file descriptor of the opened file, or -1 if an error occurred
 */
int	open_file(char *cub_name)
{
	int	fd;

	fd = open(cub_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening file failed\n");
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
