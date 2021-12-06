/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:02:51 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/06 17:53:17 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*prev[1024];
	char		*buff;
	int			ret;

	if (!prev[fd])
		prev[fd] = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_strchr(prev[fd]))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			prev[fd] = ft_join(buff, prev[fd]);
		}
	}
	free (buff);
	if (ret < 0)
		return (NULL);
	return (ft_newline(&prev[fd]));
}
