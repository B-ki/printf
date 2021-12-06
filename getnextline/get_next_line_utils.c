/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:13:57 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/06 14:34:04 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	if (ft_strlen(str) < start)
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - start + 1));
	if (!dest)
		return (NULL);
	while (str[start] && i < len)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 10)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_join(char *buff, char *prev)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(prev) + 1));
	if (!dest)
		return (NULL);
	while (prev && prev[i])
	{
		dest[i] = prev[i];
		i++;
	}
	while (buff && buff[j])
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free (prev);
	return (dest);
}

char	*ft_newline(char **prev)
{
	int		sz;
	char	*newline;
	char	*tmp;

	sz = 0;
	newline = NULL;
	tmp = *prev;
	if (*prev)
	{
		sz = ft_strchr(*prev) - *prev + 1;
		newline = ft_substr(*prev, 0, sz);
		*prev = ft_substr(*prev, sz, ft_strlen(*prev) - sz);
		free (tmp);
		return (newline);
	}
	return (NULL);
}
