/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:38 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/02 00:18:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stock = NULL;
	char		*s;
	char		*tmp;
	char		*buff;
	int			ret;

	s = NULL;
	if (!s)
	{
		s = malloc(sizeof(*s));
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	tmp = NULL;
	ret = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return NULL;
	if (!stock)
	{
		stock = malloc(sizeof(*stock));
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	while (ret != 0 && !ft_strchr(stock, 10))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		stock = buff;
		tmp = s;
		if (!ft_strchr(stock, 10))
			s = ft_strjoin(s, stock);
		free(tmp);
	}
	tmp = s;
	printf("%s\n", ft_stock(stock));
	printf("%s\n", s);
	s = ft_strjoin(s, ft_stock(stock));
	free (tmp);
	free(buff);
	return (s);
}

char	*ft_stock(char *stock)
{
	int		i;
	char	*str;
	int		size_str;

	i = 0;
	if (stock)
	{
		size_str = ft_strchr(stock, 10) - stock;
		printf("%d\n", size_str);
		str = ft_substr(stock, 0, size_str);
		str[size_str + 1] = '\0';
		stock = ft_substr(stock, size_str + 1, ft_strlen(stock) - size_str + 1);
		return (str);
	}
	return (NULL);
}

int	main()
{
	int	fd;
	
	fd = open("files/test0", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	
	return (0);
}
