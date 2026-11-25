/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essia <essia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:05:18 by eskomo            #+#    #+#             */
/*   Updated: 2026/11/22 18:54:30 by essia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Like ft_strchr, but returns NULL if s is NULL.
char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_strchr(s, c));
}

/**
 * Joins remainder and buffer into a new string.
 * Frees remainder (also on failure); remainder may be NULL.
 * Return: A pointer to the newly allocated string or NULL on failure.
 */

char	*gnl_strjoin(char *remainder, char *buffer)
{
	char	*new_str;
	size_t	len_remainder;
	size_t	len_buffer;

	if (!remainder)
	{
		remainder = ft_strdup("");
		if (!remainder)
			return (NULL);
	}
	len_remainder = ft_strlen(remainder);
	len_buffer = ft_strlen(buffer);
	new_str = (char *)malloc(sizeof(char) * (len_remainder + len_buffer + 1));
	if (!new_str)
	{
		free(remainder);
		return (NULL);
	}
	ft_strlcpy(new_str, remainder, len_remainder + 1);
	ft_strlcpy(new_str + len_remainder, buffer, len_buffer + 1);
	free(remainder);
	return (new_str);
}
