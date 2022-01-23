/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:39:02 by rmorel            #+#    #+#             */
/*   Updated: 2022/01/22 11:32:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void    handler1(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)signo;
	(void)info;
	st.message[st.i] = '1';
	st.i += 1;
	st.count_zero = 0;
	if (st.i == BUFFER_SIZE - 2)
		st.buff_overflow = TRUE;
}

void    handler2(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)signo;
	st.pidclient = info->si_pid;
	st.message[st.i] = '0';
	st.i += 1;
	st.count_zero++;
	if (st.i == BUFFER_SIZE - 2)
		st.buff_overflow = TRUE;
}

int	check_end(void)
{
	int	i;
	int	count;

	i = st.i;
	count = 0;
	if (i && i % 8 == 0)
	{
		i = i - 8;
		while(i < st.i)
		{
			if (st.message[i] == '0')
				count++;
			i++;
		}
		if (count == 8)
		{
			if (kill(st.pidclient, SIGUSR1) == -1)
				ft_printf("Cant send signal to client");
			return (1);
		}
	}
	return (0);
}

_Bool	printer(void)
{
	char	*str;
	
	while (1)
	{
		pause ();
		if (check_end())
		{
			str = bin_to_str(st.message);
			ft_printf("%s", str);
			free(str);
			ft_bzero(st.message, BUFFER_SIZE);
			if (st.end_mess)
				write (1, "\n", 1);
			st.i = 0;
			st.buff_overflow = FALSE;
			st.end_mess = FALSE;
		}
	}
	return (TRUE);
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

char	*bin_to_str(char *msg)
{
	char	*str;
	int		i;
	int		b_count;

	str = malloc(sizeof(char) * (size_bin_char(msg) + 1));
	if (!str)
		return NULL;
	ft_bzero(str, size_bin_char(msg));
	i = 0;
	b_count = 7;
	while (i < size_bin_char(msg))
	{
		while (b_count >= 0)
		{
			if (msg[i * 8 + b_count] == '1')
				str[i] += 1 << (7 - b_count);
			b_count--;
		}
		i++;
		b_count = 7;
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	pid_t	pid;
	struct sigaction sa1;
	struct sigaction sa2;

	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = handler1;
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = handler2;
	sigemptyset(&sa1.sa_mask);
	sigemptyset(&sa2.sa_mask);
	pid = getpid();
	ft_printf("PID is : %d\n", pid);
	if (sigaction(SIGUSR1, &sa1, NULL) != 0)
	{
		ft_printf("Erreur de signal SIGUSR1");
	}
	if (sigaction(SIGUSR2, &sa2, NULL) != 0)
	{
		ft_printf("Erreur de signal SIGUSR2");
	}
	ft_bzero(st.message, BUFFER_SIZE);
	printer();
	return (0);
}