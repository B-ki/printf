/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:16:56 by rmorel            #+#    #+#             */
/*   Updated: 2022/01/22 11:34:16 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    error(char *str)
{
    ft_printf("Erreur, 2 arguments only: ./client <pid> <str>\n", str);
	exit(0);
}

int main (int ac, char **av)
{
	char	*bin;
	pid_t	pid;

	pid = (pid_t)ft_atoi(av[1]);
	if (ac != 3)
	    error(av[0]);
	signal(SIGUSR1, success);
	bin = binary_converter(av[2]);
	send_binary(bin, pid);
	return (0);
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

void	success(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("All data have been printed !\n");
}

void	send_binary(char *bin, pid_t pid)
{
	int	i;

	i = 0;
	while(bin[i])
	{
		if (bin[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
	i = 0;
	while (i <= 7)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}