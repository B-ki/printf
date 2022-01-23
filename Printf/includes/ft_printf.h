/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:50:19 by rmorel            #+#    #+#             */
/*   Updated: 2021/12/16 19:56:34 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_conv
{
	char			hashtag;
	char			space;
	char			plus;
	char			minus;
	char			zero;
	char			point;
	int				i_point;
	int				width;
	char			convert;
	int				arg_c;
	char			*arg_str;
	void			*arg_p;
	long int		arg_i;
	unsigned int	arg_u;
	char			n_case;
}				t_conv;

/* ft_printf.c */
int		ft_printf(const char *s, ...);

/* print.c */
void	print_convert(va_list args, const char *s);
void	print_stock(t_conv *stock);
int		print_all(va_list args, const char *s);

/* utils.c */
int		ft_isconvert(char c);
int		ft_isnumeric(int c);
int		ft_check_nonum_before(const char *s, int i);
int		max_two_int(int a, int b);
int		max_stock(t_conv *stock, int size_num);

/* utils2_put.c */
int		ft_putchar_ret(int c, int fd, int a);
void	ft_putstr_ret(char *s, int size);
void	ft_putnbr_base(unsigned long int i, char *base, t_conv *stock);
void	ft_putnbr(long int i, t_conv *stock);
void	ft_putunbr(unsigned int i, t_conv *stock);

/* utils3_size.c */
int		get_size_hex_ulp(unsigned long int ul_p, t_conv *stock);
int		get_size_all_int(t_conv *stock);
int		get_size_only_num(t_conv *stock);
int		get_size_u(t_conv *stock);

/* char.c */
void	print_char(t_conv *stock);

/* string.c */
void	print_str(t_conv *stock);
void	print_str_no_minus_width(t_conv *stock, int size);
void	print_str_minus_width(t_conv *stock, int size);

/* pointer.c */
void	print_p(t_conv *stock);
void	print_p_no_minus(t_conv *stock, int size, unsigned long int ul_p);
void	print_p_minus(t_conv *stock, int size, unsigned long int ul_p);

/* hexadecimal.c */
void	print_x(t_conv *stock, char *base);
void	print_hex_minus_width(t_conv *stock, int size_num, int max, char *base);
void	print_hex_minus(t_conv *stock, int size_num, char *base);
void	print_hex_zero_no_point(t_conv *stock, int size_num, char *base);
void	print_hex_no_zero(t_conv *stock, int size_num, int max, char *base);

/* int.c */
void	print_d_i(t_conv *stock);
void	print_int_minus_width(t_conv *stock, int size_num, int max_minus);
void	print_int_minus(t_conv *stock, int size_num);
void	print_int_zero_no_point(t_conv *stock, int size_all);
void	print_int_no_zero(t_conv *stock, int max_no_m, int size_num);

/* unsigned.c */
void	print_u(t_conv *stock);
void	print_ui_minus_width(t_conv *stock, int size_num, int max);
void	print_ui_minus(t_conv *stock, int size_num);
void	print_ui_zero_no_point(t_conv *stock, int size_num);
void	print_ui_no_zero(t_conv *stock, int size_num, int max);

/* percent.c */
void	print_percent(t_conv *stock);

/* struct.c */
void	fill_stock_all(va_list args, const char *s, t_conv *stock);
void	fill_stock1(const char *s, t_conv *stock);
void	fill_stock2(const char *s, t_conv *stock);
void	newstock(t_conv *stock);
void	fill_stock_null(t_conv *stock);

/* libft */
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);

#endif
