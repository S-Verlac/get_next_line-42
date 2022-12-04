/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:01:34 by mbachar           #+#    #+#             */
/*   Updated: 2022/12/04 19:14:19 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		line[i] = stash[i];
		i++;
	}
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
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == 0)
		return (free(stash), NULL);
	next_data = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!next_data)
		return (NULL);
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
	{
		next_data[j] = stash[i];
		i++;
		j++;
	}
	next_data[j] = '\0';
	return (free(stash), next_data);
}

char	*ft_read(int fd, char *stash)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i > 0 && !ft_strchr(stash, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !stash)
			|| (i == 0 && stash[0] == 0))
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	stash[fd] = ft_store(stash[fd]);
	return (line);
}
