/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:38 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/02 18:50:55 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*s;
	char		*buff;
	int			ret;

	if (!stock)
		stock = NULL;
	s = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_search_nl(stock))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		stock = ft_strcpy(buff);
		if (!ft_search_nl(stock))
		{
			s = ft_strjoin_freetwo(s, stock);
			stock = NULL;
		}
	}
	if (ret <= 0)
		return (NULL);
	s = ft_strjoin_freetwo(s, ft_stock(&stock));
	free (buff);
	if (stock[0] == '\0')
		free(stock);
	return (s);
}

char	*ft_stock(char **stock)
{
	char	*str;
	int		sz;

	sz = 0;
	if (*stock)
	{
		sz = ft_search_nl(*stock) - *stock;
		str = ft_substr(*stock, 0, sz);
		*stock = ft_substr(*stock, sz + 1, ft_strlen(*stock) - sz + 1);
		return (str);
	}
	return (NULL);
}

char	*ft_strcpy(char *buff)
{
	char	*stock;
	int		i;

	i = 0;
	stock = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!stock)
		return (NULL);
	while (buff && buff[i])
	{
		stock[i] = buff[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

char	*ft_strjoin_freetwo(char const *s1, char const *s2)
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
	free ((void *)s2);
	return (dest);
}

/*int	main()
{
	int	fd;
	
	fd = open("files/test0", O_RDONLY);
	char *res = get_next_line(fd);
	printf("%s\n", res);
	free (res);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	return (0);
}*/
