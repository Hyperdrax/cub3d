/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essia <essia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:04:52 by eskomo            #+#    #+#             */
/*   Updated: 2026/11/22 18:55:34 by essia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_readline(int fd, char *remainder);
static char	*gnl_extract_line(char **remainder);
static void	gnl_leftover(char *leftover, char **remainder);

char	*get_next_line(int fd)
{
	char		*remainder;
	char		*line;
	static char	leftover[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = NULL;
	if (leftover[fd][0] != '\0')
	{
		remainder = ft_strdup(leftover[fd]);
		if (!remainder)
			return (NULL);
	}
	remainder = gnl_readline(fd, remainder);
	if (!remainder)
	{
		leftover[fd][0] = '\0';
		return (NULL);
	}
	line = gnl_extract_line(&remainder);
	gnl_leftover(leftover[fd], &remainder);
	return (line);
}

/**
 * Read from fd until a newline is found or EOF is reached.
 * Return: The updated remainder string, or NULL on error.
 */

static char	*gnl_readline(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remainder), NULL);
	bytes_read = 1;
	while (!gnl_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = gnl_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (remainder);
}

/**
 * Extracts the first line (incl. '\n') from remainder.
 * Return: The extracted line, or NULL if empty / allocation fails.
 */

static char	*gnl_extract_line(char **remainder)
{
	char	*line;
	size_t	i;

	if (!remainder || !*remainder || (*remainder)[0] == '\0')
		return (NULL);
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *remainder, i + 1);
	return (line);
}

// Stores everything after the current line in leftover and frees remainder.
static void	gnl_leftover(char *leftover, char **remainder)
{
	size_t	i;

	if (!remainder || !*remainder)
	{
		leftover[0] = '\0';
		return ;
	}
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	if ((*remainder)[i] == '\0')
		leftover[0] = '\0';
	else
		ft_strlcpy(leftover, &(*remainder)[i],
			ft_strlen(&(*remainder)[i]) + 1);
	free(*remainder);
	*remainder = NULL;
}
