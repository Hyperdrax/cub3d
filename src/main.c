//42-Header

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error("Invalid number of arguments. Only 2 arguments!"));
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			return (print_error("Invalid file extension. Expected .cub"));
		ft_bzero(&data, sizeof(t_data));
		if (parser(argv[1], &data) != 0)
		{
			//perror("Error\nFailed to parse the file\n"); Not sure, since the parser already prints errors
			return (1);
		}
	}
	return (0);
}
