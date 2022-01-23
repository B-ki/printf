/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:38:36 by rmorel            #+#    #+#             */
/*   Updated: 2022/01/21 17:57:44 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"
# include <stdbool.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 1
# endif

# define BUFFER_SIZE 1024

void    handler1(int signo, siginfo_t *info, void *context);
void    handler2(int signo, siginfo_t *info, void *context);
_Bool	printer(void);
int		size_bin_char(char *msg);
char	*bin_to_str(char *msg);
int		check_end(void);
int		ft_printf(const char *s, ...);
void	ft_bzero(void *s, size_t n);


typedef struct s_stock {
	pid_t 			pidclient;
	int				i;
	int				count_zero;
	_Bool			end_mess;
	_Bool			buff_overflow;
	char			message[BUFFER_SIZE];
}	t_stock;

t_stock st = {0, 0, 0, FALSE, FALSE, {0}};

#endif