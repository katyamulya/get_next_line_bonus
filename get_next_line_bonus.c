/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:31:33 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/17 11:29:03 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*rline;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd], &r);
	if (r == -1)
		return (free(buffer[fd]), NULL);
	if (!buffer[fd])
		return (NULL);
	rline = ft_get_line(buffer[fd]);
	buffer[fd] = ft_get_buffer(buffer[fd]);
	return (rline);
}

char	*ft_read(int fd, char *buffer, int *r)
{
	char	*line;

	if (!buffer)
		buffer = ft_calloc_bzero(1, 1);
	line = ft_calloc_bzero(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	(*r) = 1;
	while ((*r) > 0)
	{
		(*r) = read(fd, line, BUFFER_SIZE);
		if ((*r) == 0)
			break ;
		if ((*r) == -1)
			return (free(line), free(buffer), NULL);
		line[(*r)] = '\0';
		buffer = ft_joinnfree(buffer, line);
		if (ft_strch(line, '\n') == 1)
			break ;
	}
	free(line);
	return (buffer);
}

char	*ft_joinnfree(char *buffer, char *line)
{
	char	*tmp;

	if (!buffer)
	{
		free(buffer);
		tmp = line;
	}
	else
	{
		tmp = ft_strjoin(buffer, line);
		free(buffer);
	}
	return (tmp);
}

char	*ft_get_line(char *buffer)
{
	char	*rline;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	if (buffer[i] != '\0' && buffer[i] == '\n')
	{
		rline = ft_calloc_bzero(i + 2, sizeof(char));
		rline[i] = '\n';
		rline[i + 1] = '\0';
		return (rline);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\0' && buffer[i] == '\n')
		rline = ft_calloc_bzero(i + 2, sizeof(char));
	else
		rline = ft_calloc_bzero(i + 1, sizeof(char));
	ft_cpy_rline(&rline, buffer);
	return (rline);
}

char	*ft_get_buffer(char *buffer)
{
	char	*buf;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	buf = ft_calloc_bzero(ft_strlen(buffer) - i + 1, sizeof(char));
	j = 0;
	while (buffer[i] != '\0')
	{
		buf[j] = buffer[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (free(buffer), buf);
}
