/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:38 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/02 15:49:36 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*const	int BUFFER_SIZE = 42;*/

char	*get_next_line(int fd)
{
	static char *stock;
	char		*s;
	char		*buff;
	int			ret;

	if (!stock)
		stock = NULL;
	s = NULL;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return NULL;
	ret = 1;
	while (ret > 0 && !ft_search_nl(stock))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		stock = ft_strcpy(buff);
		if (!ft_search_nl(stock))
			s = ft_strjoin(s, stock);
	}
	s = ft_strjoin(s, ft_stock(&stock));
	return (s);
}

char	*ft_stock(char **stock)
{
	int		i;
	char	*str;
	int		size_str;

	i = 0;
	size_str = 0;
	if (*stock)
	{
		size_str = ft_search_nl(*stock) - *stock;
		str = ft_substr(*stock, 0, size_str);
		*stock = ft_substr(*stock, size_str + 1, ft_strlen(*stock) - size_str + 1);
		return (str);
	}
	return (NULL);
}

char *ft_strcpy(char *buff)
{
	char	*stock;
	int		i;

	i = 0;
	stock = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!stock)
		return NULL;
	while (buff && buff[i])
	{
		stock[i] = buff [i];
		i++;
	}
	stock[i] = '\0';
	free (buff);
	return (stock);
}

int	main()
{
	int	fd;
	
	fd = open("files/test0", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	return (0);
}
