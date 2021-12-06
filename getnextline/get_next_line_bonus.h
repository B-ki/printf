/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:10:40 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/06 17:53:40 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char				*get_next_line(int fd);
char				*ft_join(char *buff, char *prev);
unsigned int		ft_strlen(char *str);
char				*ft_strchr(char *str);
char				*ft_newline(char **prev);
char				*ft_substr(char *str, unsigned int start, size_t len);

#endif