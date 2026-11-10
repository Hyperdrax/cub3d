//42-Header

#include "cub3d.h"

/**
 * Check if the file has the correct extension (.cub)
 * @param cub_name The name of the file to check
 * @return 1 if the file has the correct ending (.cub)
 *		   0 otherwise
 */
int	check_extension(char *cub_name)
{
	int	len;

	len = ft_strlen(cub_name);
	if (ft_strncmp(cub_name + len - 4, ".cub", 5) != 0)
		return (0);
	return (1);
}
