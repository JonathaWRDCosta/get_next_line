/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:29:16 by jonathro          #+#    #+#             */
/*   Updated: 2024/12/11 10:27:50 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(save), NULL);
	byte_read = 1;
	while (!ft_find_newline(save) && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(save), NULL);
		buffer[byte_read] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (save);
}

static char	*ft_split_line(char *save)
{
	int		i;
	char	*line;

	if (!save || !*save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_trim_line(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	new_save = (char *)malloc(ft_strlen(save) - i);
	if (!new_save)
		return (free(save), NULL);
	i++;
	j = 0;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_split_line(save);
	save = ft_trim_line(save);
	if (!line || (line[0] == '\0' && !save))
		return (free(line), NULL);
	return (line);
}
