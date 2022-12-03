/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:39:35 by mbachar           #+#    #+#             */
/*   Updated: 2022/12/02 19:55:42 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == 0)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		line[i++] = stash[i++];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_store(char *stash)
{
	char	*next_data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	next_data = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!next_data)
		return (NULL);
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
		next_data[j++] = stash[i++];
	next_data[j] = '\0';
	return (free(stash), next_data);
}

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != 0 && (ft_strchr(buff, '\n') == 0))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_store(stash);
	return (line);
}
