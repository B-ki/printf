/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:57:39 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/06 14:34:12 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*buff;
	int			ret;

	if (!prev)
		prev = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_strchr(prev))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			prev = ft_join(buff, prev);
		}
	}
	free (buff);
	if (ret < 0)
		return (NULL);
	return (ft_newline(&prev));
}
