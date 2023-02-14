/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:02:30 by ahovakim          #+#    #+#             */
/*   Updated: 2023/02/14 15:46:35 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*reading(int fd, char *buf, char *remainder)
{
	char	*temp;
	int		read_line;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (remainder);
}

static char	*remaining(char **line)
{
	char	*remainder;
	int		count;

	count = ft_strlen(*line) - ft_strlen(ft_strchr (*line, '\n'));
	if (line[0][count] == '\0' || line[0][1] == '\0')
		return (NULL);
	remainder = ft_substr(*line, count + 1, ft_strlen(*line) - count);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[0][count + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buf;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = reading(fd, buf, remainder);
	free(buf);
	if (!line)
		return (NULL);
	remainder = remaining(&line);
	return (line);
}
