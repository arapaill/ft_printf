/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:14:56 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/10 10:29:44 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef unsigned char	t_flags;

# define FLAG_ZERO		1
# define FLAG_DIGIT		2
# define FLAG_MINUS		4
# define FLAG_DOT		8

typedef struct		s_format
{
	t_flags			flags;
	int				min_field;
	int				precision;
	size_t			size;
}					t_format;

int					ft_printf(const char *s, ...);

/*
** utils
*/
char				*ft_itoabase(unsigned int n);
char				*ft_u_itoa(unsigned long long n);
int					is_arg(char c);
int					spamotron(char c, int size);
char				*ft_llu_itoabase(long long unsigned i, char *base);

/*
** arg
*/
int					case_c(int c, t_format form);
int					case_s(char *s, t_format form);
int					case_p(long long unsigned adress, t_format form);
int					arg_d(signed long int nb, t_format form);
int					case_u(unsigned int i, t_format form);
int					case_x(size_t nb, char c, t_format form);
int					case_prct(t_format form);

/*
** flags
*/
t_format			flags_ini(t_format *arg_list);
t_format			flags_chr(int *j, const char *s,
								t_format arg_list, va_list arg);
t_format			flags_presetting(const char *s,
									t_format arg_list, va_list arg);
t_format			minus_setting(const char *s,
									t_format arg_list, va_list arg);
t_format			zero_setting(const char *s, t_format arg_list, va_list arg);
t_format			digit_setting(const char *s,
									t_format arg_list, va_list arg);
t_format			dot_setting(const char *s, t_format arg_list, va_list arg);

#endif
