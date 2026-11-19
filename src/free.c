//42-Header

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
