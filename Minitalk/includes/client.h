/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:30 by rmorel            #+#    #+#             */
/*   Updated: 2022/01/20 19:24:24 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft.h"

void    error(char *str);
char	*binary_converter(char *str);
void	send_binary(char *bin, pid_t pid);
int		ft_printf(const char *s, ...);
void	success(int signum);

#endif