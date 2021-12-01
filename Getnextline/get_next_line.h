/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:29:30 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/01 19:04:01 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
void	ft_putstr(char *str);
char	*ft_newline_to_str(int fd, int start_index);
int		ft_get_size(int fd, int start_index);
int		ft_get_newline(char *str[BUFFER_SIZE]);

#endif
