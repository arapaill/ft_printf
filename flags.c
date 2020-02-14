/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:30:53 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/14 11:35:17 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		flags_ini(t_format *arg_list)
{
	arg_list->flags = 0;
	arg_list->min_field = -1;
	arg_list->precision = 0;
	arg_list->size = 0;
	return (*arg_list);
}
t_format	flags_presetting(const char *s, t_format *arg_list, va_list arg)
{
	if (arg_list->flags & FLAG_MINUS)
		return (minus_setting(s, &arg_list, arg));
	if (arg_list->flags & FLAG_ZERO)
		return (zero_setting(s, &arg_list, arg));
	if (arg_list->flags & FLAG_DIGIT)
		return (digit_setting(s, &arg_list, arg));
	if (arg_list->flags & FLAG_DOT)
		return (dot_setting(s, &arg_list, arg));
}

t_format		flags_chr(int *j, const char *s, t_format *arg_list, va_list arg)
{
	int		i;

	i = 0;
	while (!(is_arg(s[i])) && s[i] != '%' && s[i])
	{
		if (s[i] == '0' && i == 0)
			arg_list->flags |= FLAG_ZERO;
		else if (s[i] == '.')
			arg_list->flags |= FLAG_DOT;
		else if (s[i] == '-')
			arg_list->flags |= FLAG_MINUS;
		else if ((ft_isdigit(s[i]) && i == 0) || (s[i] == '*' && i == 0))
			arg_list->flags |= FLAG_DIGIT;
		i++;
	}
	*j = i;
	if (arg_list->flags & FLAG_MINUS && arg_list->flags & FLAG_ZERO)
		arg_list->flags -= FLAG_ZERO;
	return (flags_presetting(s, &arg_list, arg));
}
