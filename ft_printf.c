/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:05:37 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/09 12:11:46 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				trieur(const char *s, va_list arg, t_format arg_list)
{
	int		i;
	int		ret;
	int		size;

	i = 0;
	size = 0;
	arg_list = flags_chr(&i, s, arg_list, arg);
	if (s[i] == 'c')
		ret = case_c(va_arg(arg, int), arg_list);
	if (s[i] == 's')
		ret = case_s(va_arg(arg, char *), arg_list);
	if (s[i] == 'p')
		ret = case_p(va_arg(arg, long long int), arg_list);
	if (s[i] == 'd' || s[i] == 'i')
		ret = arg_d(va_arg(arg, int), arg_list);
	if (s[i] == 'u')
		ret = case_u(va_arg(arg, unsigned long long), arg_list);
	if (s[i] == 'x' || s[i] == 'X')
		ret = case_x(va_arg(arg, size_t), s[i], arg_list);
	if (s[i] == '%')
		ret = case_prct(arg_list);
	if (ret == -1)
		return (-1);
	size += ret;
	return (size);
}

static int		ft_printf_nxt(const char *s, int i,
								t_format arg_list, va_list args)
{
	int		saved_i;
	int		tmp;

	while (s[i])
		if (s[i] == '%')
		{
			saved_i = i;
			arg_list = flags_ini(&arg_list);
			if ((tmp = trieur(&s[++i], args, arg_list)) == -1)
				return (-1);
			arg_list.size += tmp;
			while (is_arg(s[i]) == 0 && s[i])
				i++;
			if (s[i] == '\0')
			{
				i = saved_i;
				while ((s[i] && s[i] == '%')
				|| s[i] == '-' || ft_isdigit(s[i]) || s[i] == '.')
					i++;
			}
			i += s[i] == '\0' ? 0 : 1;
		}
		else
			arg_list.size += write(1, &s[i++], 1);
	return (arg_list.size);
}

int				ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	t_format	arg_list;

	if (s == NULL || s[0] == '\0')
		return (-1);
	i = 0;
	va_start(args, s);
	arg_list.size = 0;
	arg_list.size += ft_printf_nxt(s, i, arg_list, args);
	va_end(args);
	return (arg_list.size);
}
