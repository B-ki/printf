/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:18:23 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/02 17:53:47 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<stdio.h>

char	*get_next_line(int fd);
char	*ft_search_nl(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_size(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_stock(char **stock);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *buff);
char	*ft_strjoin_freetwo(char const *s1, char const *s2);

#endif
