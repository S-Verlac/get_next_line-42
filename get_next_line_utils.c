/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:41:06 by mbachar           #+#    #+#             */
/*   Updated: 2022/12/03 16:33:31 by mbachar          ###   ########.fr       */
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
	int		i;
	int		len1;
	char	*str;

	if (!s1)
		ft_strdup("");
	if (s2)
	{
		len1 = ft_strlen(s1);
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
