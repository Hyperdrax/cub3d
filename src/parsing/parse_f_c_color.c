//42-Header

#include "cub3d.h"

/**
 * skips leading whitespaces in a string and returns a ptr to
 * the first non-whitespace char after leading spaces.
 */
static char	*skip_spaces(char *ptr)
{
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	return (ptr);
}

/**
 * Skips leading whitespaces, identifie the type of color in line (F or C) and returns it.
 * If the line does not start with F/C after skipping spaces, returns 0.
 * increment the line pointer to point after the type char.
 */
static char	identify_type(char **line)
{
	char	*ptr;
	char	type;

	ptr = skip_spaces(*line);
	if (*ptr != 'F' && *ptr != 'C')
		return (0);
	type = *ptr;
	if (!ft_isspace(ptr[1]))
		return (0);
	ptr++;
	*line = ptr;
	return (type);
}

/**
 * Counts the number of commas in the line.
 * (If it is not exactly 2, the RGB format is invalid.)
 * Retruns the number of commas found.
 */
static int	count_commas(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

/**
 * Checks if the RGB value are in the range (0-255).
 * Returns 1 if any value is out of range, 0 otherwise.
 */
static int	check_range(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Pareses a single component of the RGB color, passed as a string by parse_rgb().
 * Skips leading spaces (by incrementing 'start' which represents the index of the first non-space char),
 * then checks if the component is a valid interger (starting by i = start and incrementing i while the char is a digit).
 * If there are elements after leading spaces (start != i) and the length of the component is less then 4, retrun 1 (invalid).
 * Skips trailing spaces and checks if there are any non-space characters after the component (if so, return 1).
 * Convert the component to an integer (ft_atoi) and store it in the value pointer.
 * Returns 0 by success, 1 by failure.
 */
static int	parse_component(char *split, int *value)
{
	int	start;
	int	i;

	start = 0;
	while (split[start] && ft_isspace(split[start]))
		start++;
	i = start;
	while (ft_isdigit(split[i]))
		i++;
	if (i == start || i - start > 3)
		return (1);
	if (*skip_spaces(split + i) != '\0')
		return (1);
	*value = ft_atoi(split + start);
	return (0);
}

/**
 * Parses the RGB color from the line, which is expected to be in the format "R,G,B" (with exactly 2 commas).
 * Splits the line by commas and parses each component with parse_component().
 * If number of components is not 3 or any component is invalid returns 1 (error).
 * Otherwise, stores RGB values in the color array and returns 0 (success).
 */
static int	parse_rgb(char *line, int color[3])
{
	char	**splits;
	int		i;
	int		ret;

	if (count_commas(line) != 2)
		return (1);
	splits = ft_split(line, ',');
	if (!splits)
		return (1);
	ret = 0;
	i = 0;
	while (i < 3 && ret == 0)
	{
		if (!splits[i] || parse_component(splits[i], &color[i]))
			ret = 1;
		i++;
	}
	free_split(splits);
	return (ret);
}

int	parse_f_c_color(char *line, t_data *data)
{
	char	type;
	int		color[3];

	type = identify_type(&line);
	if (!type)
		return (print_error("Invalid color line: expected 'F' or 'C'"));
	if (parse_rgb(line, color))
		return (print_error("Invalid RGB format (expected R,G,B)"));
	if (check_range(color))
		return (print_error("RGB values must be between 0 and 255"));
	if (type == 'F')
	{
		data->floor_color.r = color[0];
		data->floor_color.g = color[1];
		data->floor_color.b = color[2];
	}
	else if (type == 'C')
	{
		data->ceiling_color.r = color[0];
		data->ceiling_color.g = color[1];
		data->ceiling_color.b = color[2];
	}
	return (0);
}
