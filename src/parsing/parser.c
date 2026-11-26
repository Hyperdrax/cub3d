//42-Header
#include "cub3d.h"

/**
 * Removes the newline character from the end of the line if it exist
 */
static void	remove_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static t_error_code	read_lines_to_list(int fd, t_list **list)
{
	char	*line;
	t_list	*new_node;

	while ((line = get_next_line(fd)) != NULL)
	{
		remove_newline(line);
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(list, free);
			return (ERR_ALLOC);
		}
		ft_lstadd_back(list, new_node);
	}
	if (*list == NULL)
		return (ERR_EMPTY_FILE);
	return (ERR_OK);
}

/**
 * Open the file with the given name and store the file descriptor in the provided ptr.
 * @param cub_name The name of the file to open
 * @param fd A pointer to an integer where the fd will be stored
 * @return ERR_OK if the file was opened successfully, ERR_FILE_OPEN otherwise
 */
t_error_code	open_file(int *fd, char *cub_name)
{
	fd = open(cub_name, O_RDONLY);
	if (fd == -1)
		return (ERR_FILE_OPEN);
	return (ERR_OK);
}

int	parser(char *cub_name, t_data *data)
{
	int		fd;
	t_list	*raw_data_list;

	if (open_file(&fd, cub_name) != ERR_OK)
		return (ERR_FILE_OPEN);

//...
	close(fd);
	return (0);
}
