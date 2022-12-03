/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:41:06 by mbachar           #+#    #+#             */
/*   Updated: 2022/12/02 19:19:35 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	new = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
