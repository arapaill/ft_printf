/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:05:37 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/14 11:37:32 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		trieur(const char *s, va_list arg, t_format *arg_list)
{
	int		i;
	int		ret;

	i = 0;
	*arg_list = flags_chr(&i, s, arg_list, arg);
	if (s[i] == 'c')
		ret = case_c(va_arg(arg, int), &arg_list);
	if (s[i] == 's')
		ret = case_s(va_arg(arg, char *));
	if (s[i] == 'p')
		ret = case_p(va_arg(arg, void *));
	if (s[i] == 'd' || s[i] == 'i')
		ret = case_d(va_arg(arg, int));
	if (s[i] == 'u')
		ret = case_u(va_arg(arg, unsigned long long));
	if (s[i] == 'x' || s[i] == 'X')
		ret = case_x(va_arg(arg, unsigned long long), s[i]);
	if (s[i] == '%')
		ret = case_prct();
	if (ret == -1)
		return (-1);
	arg_list->size += ret;
	return (arg_list->size);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	size_t		size;
	int			i;
	int			tmp;
	t_format	arg_list;

	if (s == NULL || s[0] == '\0')
		return (-1);
	size = 0;
	i = 0;
	va_start(args, s);
	arg_list = flags_ini(&arg_list);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if ((tmp = trieur(&s[++i], args, &arg_list)) == -1)
				return (-1);
			while (is_arg(s[i]) == 0 && s[i])
				i++;
			i++;
			size += tmp;
		}
		size += write(1, &s[i++], 1);
	}
	va_end(args);
	return (size);
}
