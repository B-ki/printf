/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:27:40 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/01 15:38:35 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *line;
	char		*buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFF_SIZE);
}

int	ft_get_size(int fd)
{
	char	*buff[BUFF_SIZE + 1];
	int		ret;
	int		size;

	buff = NULL;
	ret = 0;
	size = 0;
	while (1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret > 0)
			size = size + ret;
		else
			break;
	}
	return (size);
}

int	ft_count_char_jump_line

int	main(arg c, arg v)
{


	return (0);
}