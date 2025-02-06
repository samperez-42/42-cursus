/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:49:37 by samperez          #+#    #+#             */
/*   Updated: 2024/11/21 12:22:54 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_mem(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*update(char *trash_line)
{
	char	*tmp;
	int		linebreak;
	int		trash_len;

	linebreak = ft_strchr(trash_line, '\n');
	if (linebreak == -1)
	{
		free(trash_line);
		trash_line = NULL;
		return (NULL);
	}
	linebreak += 1;
	trash_len = ft_strlen(trash_line);
	tmp = ft_substr(trash_line, linebreak, trash_len - linebreak);
	free(trash_line);
	return (tmp);
}

static char	*clean_line(char *line, char *trash_line)
{
	int	linebreak;

	linebreak = ft_strchr(trash_line, '\n');
	if (linebreak == -1)
	{
		line = ft_strdup(trash_line);
		return (line);
	}
	line = ft_substr(trash_line, 0, linebreak + 1);
	return (line);
}

static char	*read_from_file(int fd, char *trash_line)
{
	char	*buf;
	int		bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free_mem(&buf));
	while (ft_strchr(trash_line, '\n') == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free_mem(&buf);
			return (free_mem(&trash_line));
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		trash_line = ft_strjoin(trash_line, buf);
	}
	free_mem(&buf);
	return (trash_line);
}

char	*get_next_line(int fd)
{
	static char	*trash_line;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (free_mem(&trash_line));
	if (!trash_line)
	{
		trash_line = (char *)malloc(1 * sizeof(char));
		if (!trash_line)
			return (free_mem(&trash_line));
		if (trash_line)
			trash_line[0] = '\0';
	}
	trash_line = read_from_file(fd, trash_line);
	if (!trash_line || trash_line[0] == 0)
		return (free_mem(&trash_line));
	line = clean_line(line, trash_line);
	trash_line = update(trash_line);
	return (line);
}
