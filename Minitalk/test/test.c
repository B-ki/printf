/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:25:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/01/22 11:28:22 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ps;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		ps[i] = uc;
		i++;
	}
	return (ps);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*binary_converter(char *str)
{
	char	*bin;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 7;
	c = str[0];
	bin = malloc(sizeof(char) * (ft_strlen(str) * 8 + 1));
	if (!bin)
		return (NULL);
	while (str[i])
	{
		while (j >= 0)
		{
			if (c & (1 << j))
				bin[i * 8 + 7 - j] = 1 + 48;
			else
				bin[i * 8 + 7 - j] = 0 + 48;
			j--;
		}
		i++;
		c = str[i];
		j = 7;
	}
	bin[i * 8 + 1] = '\0';
	return (bin);
}

void	ft_putnbr(int b)
{
	write(1, &b, 1);
}

int	size_bin_char(char *msg)
{
	int	i;
	int	z_count;

	i = 0;
	z_count = 0;
	while(msg[i] && z_count < 8)
	{
		if (msg[i] == '1')
			z_count = 0;
		else if (msg[i] == '0')
			z_count++;
		i++;
	}
	return (i / 8);
}

char	bin_to_char(char *str)
{
	int		b_count;
	char 	c;
	
	b_count = 7;
	c = 0;
	while (b_count >= 0)
	{
		if (str[b_count] == '1')
			c += 1 << 7 - b_count;
		b_count--;
	}
	return (c);
}

char	*bin_to_str(char *msg)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (size_bin_char(msg) + 1));
	if (!str)
		return NULL;
	ft_bzero(str, size_bin_char(msg));
	i = 0;
	j = 0;
	while (j < size_bin_char(msg))
	{
		str[j] = bin_to_char(&msg[i]);
		j++;
		i+= 8;
	}
	str[j] = '\0';
	return (str);
}

int	main(void)
{
	int		i;
	int		j;
	char	*bin;
	char 	*str;

	i = 0;
	j = 0;
	bin = binary_converter("Bonjour");
	while (bin[i])
	{
		ft_putnbr(bin[i]);
		j++;
		if (j == 8)
		{
			write(1, " ", 1);
			j = 0;
		}
		i++;
	}
	write(1, "\n", 1);
	str = bin_to_str(bin);
	printf("%s\n", str);
	return (0);
}