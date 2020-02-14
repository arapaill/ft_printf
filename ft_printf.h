/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:14:56 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/14 11:35:16 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef unsigned char	t_flags;

# define FLAG_ZERO		1
# define FLAG_DIGIT		2
# define FLAG_MINUS		4
# define FLAG_DOT		8

typedef struct	s_format
{
	t_flags			flags;
	int				min_field;
	int				precision;
	char			arg_type;
	size_t			size;
}				t_format;

int			ft_printf(const char *s, ...);

/*
* utilities
*/
char		*ft_itoabase(unsigned long long nb, int base);
char		*ft_u_itoa(unsigned long long n);
int			is_arg(char c);
int			spamotron(char c, int size);

/*
*arg
*/
int			case_c(int c, t_format *arg_list);
int			case_s(char *s);
int			case_p(void *p);
int			case_d(int nb);
int			case_u(unsigned long long nb);
int			case_x(unsigned long long nb, char c);
int			case_prct(void);

/*
* flags
*/
t_format	flags_ini(t_format *arg_list);
t_format	flags_chr(int *j, const char *s, t_format *arg_list, va_list arg);
t_format	minus_setting(const char *s, t_format *arg_list, va_list arg);
t_format	zero_setting(const char *s, t_format *arg_list, va_list arg);
t_format	digit_setting(const char *s, t_format *arg_list, va_list arg);
t_format	dot_setting(const char *s, t_format *arg_list, va_list arg);
#endif