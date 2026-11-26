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

/**
 * Returns the error message corresponding to the given error code.
 * @param err_code The error code for which to set the error message
 * @return The error message corresponding to the given error code
 */
static const char	*error_messages(t_error_code err_code)
{
	static const char	*msg[] = {
		"Success",
		"Incorrect usage (e.g. wrong number of arguments)",
		"File extension is not .cub",
		"File could not be opened (e.g. file doesn't exist, permission denied)",
		"File could not be read",
		"Memory allocation failed",
		"Unknown identifier in the .cub file",
		"Duplicate elemnent in the .cub file",
		"Missing a required element in the .cub file",
		"Invalid color (e.g. wrong format, values...)",
		"Invalid RGB value (e.g. not a number)",
		"RGB out of range (0-255)",
		"Texture file doesn't exist, permission denied",
		"Invalid map character (not a 1, 0, space or player direction",
		"Map is not closed (e.g. open/missing walls)",
		"Not exactly one player in the map!",
		"The .cub file is empty",
		"Texture path is invalid",
		"The map is missing in the .cub file",
		"Map is interrupted by empty lines/other elements"
	};

	if (err_code < 0 || err_code > 19)
		return ("Unknown error code");
	return (msg[err_code]);
}

/**
 * Handles the error based on the given error code.
 * If the error code is ERR_OK, returns 0 (no error).
 * Otherwise, prints the corresponding error message and returns 1 (error).
 * @param err_code The error code to handle
 * @return 0 if no error, 1 if an error occurred
 */
int	err_handler(t_error_code err_code)
{
	if (err_code == ERR_OK)
		return (0);
	print_error(error_messages(err_code));
	return (1);
}
