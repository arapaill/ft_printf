/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:53:11 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/04 16:56:46 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	minus_setting(const char *s, t_format arg_list, va_list arg)
{
	int		i;

	i = 0;
	while (s[i] != '-')
		i++;
	while (s[i] == '-')
		i++;
	if (ft_isdigit(s[i]))
		arg_list.min_field = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		arg_list.min_field = va_arg(arg, int);
		if (arg_list.min_field < 0)
			arg_list.min_field *= -1;
	}
	return (arg_list);
}

t_format	zero_setting(const char *s, t_format arg_list, va_list arg)
{
	int		i;

	i = 0;
	while (s[i] != '0')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_isdigit(s[i]))
		arg_list.min_field = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		arg_list.min_field = va_arg(arg, int);
		if (arg_list.min_field < 0)
		{
			arg_list.flags += FLAG_MINUS;
			arg_list.flags -= FLAG_ZERO;
			arg_list.min_field *= -1;
		}
	}
	return (arg_list);
}

t_format	digit_setting(const char *s, t_format arg_list, va_list arg)
{
	int		i;

	i = 0;
	if (i == 0 && s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		va_arg(arg, int);
		arg_list.min_field = ft_atoi(&s[++i]);
		return (arg_list);
	}
	while (!(ft_isdigit(s[i])) && s[i] != '*')
		i++;
	if (s[i] == '*')
	{
		arg_list.min_field = va_arg(arg, int);
		if (arg_list.min_field < 0)
		{
			arg_list.flags |= FLAG_MINUS;
			arg_list.flags &= ~FLAG_DIGIT;
			arg_list.min_field *= -1;
		}
	}
	else
		arg_list.min_field = ft_atoi(&s[i]);
	return (arg_list);
}

t_format	dot_setting(const char *s, t_format arg_list, va_list arg)
{
	int		i;

	i = 0;
	while (s[i] != '.')
		i++;
	while (s[i] == '.')
		i++;
	if (ft_isdigit(s[i]))
		arg_list.precision = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		arg_list.precision = va_arg(arg, int);
		if (arg_list.precision < 0)
			arg_list.flags &= ~FLAG_DOT;
	}
	return (arg_list);
}
