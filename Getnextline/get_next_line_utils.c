/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:29:05 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/02 17:40:03 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	dest = malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free ((void *)s1);
	return (dest);
}

char	*ft_search_nl(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == 10)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == 10)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_size(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	while (s[start + i])
		i++;
	if (i < len)
		return (i);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(sizeof(*dest) * 1);
		if (!dest)
			return (0);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(*dest) * (ft_size(s, start, len) + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
