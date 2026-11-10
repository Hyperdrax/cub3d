//42-Header

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!check_extension(argv[1]))
		{
			perror("Error: Invalid file extension. Expected .cub\n");
			return (1);
		}
		//init data (NULL)
		if (parser(argv[1], &data) != 0)
		{
			perror("Error: Failed to parse the file\n");
			return (1);
		}
	}
	return (0);
}
