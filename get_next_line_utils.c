/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:26:08 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/01/08 12:26:15 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	char	*joined;

	if (!s1 || !s2)
		return (0);
	if (!(joined = (char *)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	*joined = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	t = 0;
	while (s2[t] != '\0')
	{
		joined[i + t] = s2[t];
		t++;
	}
	joined[i + t] = '\0';
	return (joined);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	copy = (char*)malloc(sizeof(char) * (i + 1));
	if (!copy)
	{
		return (0);
	}
	j = 0;
	while (src[j] != 0)
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int n)
{
	while (*s)
	{
		if (*s == n)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == 0 && n == 0)
		return ((char *)s);
	return (0);
}