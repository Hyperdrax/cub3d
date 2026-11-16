//42-Header

#include "cub3d.h"

/**
 * Print an error message to the standard error output (for parsing/validation erors)
 * @param error_msg The error message to print
 * @return Always returns 1
 */
int	print_error(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
