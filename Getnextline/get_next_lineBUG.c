/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineBUG.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:27:40 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/01 21:33:38 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	start_index;
	char		*str;

	str = ft_newline_to_str(fd, start_index);
	ft_putstr(str);
	start_index = start_index + ft_get_size(fd, start_index); 
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_newline_to_str(int fd, int start_index)
{
	char	*s;
	char	*skip[start_index];
	int		ret;

	ret = read(fd, skip, start_index);
	s = malloc(sizeof(char) * (ft_get_size(fd, start_index) + 1));
	if (s)
	{
		printf("%d\n", start_index);
		printf("%d\n", ft_get_size(fd, start_index));
		ret = read (fd, s, ft_get_size(fd, start_index));
		s[ret] = '\0';
		return (s);
	}
	return (NULL);
}

int	ft_get_size(int fd, int start_index)
{
	char	*buff[BUFFER_SIZE];
	char	*skip[start_index];
	int		ret;
	int		size;

	ret = 0;
	size = 0;
	ret = read(fd, skip, start_index);
	while (1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0 && ft_get_newline(buff) == BUFFER_SIZE)
			size = size + ret;
		else if (ret > 0)
		{
			size = size + ft_get_newline(buff);
			break ;
		}
		else
			break ;
	}
	return (size);
}

int	ft_get_newline(char *str[BUFFER_SIZE])
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && i != '\n' && i < BUFFER_SIZE)
		i++;
	return (i);
}

int	main()
{
	int	fd;
	
	fd = open("files/test0", O_RDONLY);
	get_next_line(fd);
	return (0);
}
