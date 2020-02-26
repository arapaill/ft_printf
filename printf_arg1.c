/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:58:46 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/26 14:15:27 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_c(int c, t_format arg_list)
{
	int size;

	size = 0;
	if (arg_list.flags & FLAG_ZERO)
		size += spamotron('0', arg_list.min_field - 1);
	if (arg_list.flags & FLAG_DIGIT)
		size += spamotron(' ', arg_list.min_field - 1);
	size += write(1, &c, 1);
	if (arg_list.flags & FLAG_MINUS)
		size += spamotron(' ', arg_list.min_field - 1);
	return (size);
}

int		case_s(char *s, t_format arg_list)
{
	int				size_s;
	int 			size;
	int				mem;

	mem = 0;
	size = 0;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		mem = 1;
	}
	size_s = ft_strlen(s);
	if (arg_list.flags & FLAG_DOT && arg_list.precision < (int)ft_strlen(s))
		size_s = arg_list.precision;
	if (arg_list.flags & FLAG_DIGIT)
		size += spamotron(' ', arg_list.min_field - size_s);
	if (arg_list.flags & FLAG_ZERO)
		size += spamotron('0', arg_list.min_field - size_s);
	if (arg_list.flags & FLAG_DOT && arg_list.precision < (int)ft_strlen(s))
		size += write(1, s, arg_list.precision);
	else
		size += write(1, s, ft_strlen(s));
	if (arg_list.flags & FLAG_MINUS && size_s < arg_list.min_field)
		size += spamotron(' ', arg_list.min_field - size_s);
	if (mem == 1)
		free(s);
	return (size);
}

int		case_p(long long unsigned p, t_format arg_list)
{
	int				i;
	int				size;
	char			*array;

	size = 0;
	printf("\n________TEST_________\n");
	if(!(array = ft_itoabase(p, 16)))
		return (-1);
	i = ft_strlen(array);
	if (p == 0 && arg_list.flags & FLAG_DOT && i > 0)
		i--;
	if (arg_list.flags & FLAG_DIGIT)
		size += spamotron(' ', arg_list.min_field - (i + 2));
	size += write(1, "0x", 2);
	if (arg_list.flags & FLAG_DOT)
		size += spamotron('0', arg_list.precision - i);
	if (arg_list.flags & FLAG_ZERO)
		size += spamotron('0', arg_list.min_field - i - 2);
	size += write(1, array, i);
	if (arg_list.flags & FLAG_MINUS && i < arg_list.min_field)
		size += spamotron(' ', arg_list.min_field - (i + 2));
	free(array);
	return (size);
}

int		case_d(int nb, t_format arg_list)
{
	int				size_n;
	int				neg;
	int				size;
	long long int	n;
	char			*array;

	neg = 0;
	size = 0;
	n = nb;
	if (nb < 0)
	{
		neg = 1;
		n = nb *(-1);
	}
	if(!(array = ft_itoa(n)))
		return(-1);
	size_n = ft_strlen(array) + neg;
	if(n == 0 && arg_list.flags & FLAG_DOT && size_n > 0)
		size_n--;
	if (arg_list.flags & FLAG_DIGIT && arg_list.precision < size_n)
		size += spamotron(' ', arg_list.min_field - size_n);
	else if (arg_list.flags & (FLAG_DIGIT | FLAG_ZERO) && arg_list.flags & FLAG_DOT)
		{
			if(arg_list.precision >= size_n)
				size += spamotron(' ', arg_list.min_field - (arg_list.precision + neg));
			else
				size += spamotron(' ', arg_list.min_field - size_n);
		}
	if (neg == 1)
		size += write(1, "-", 1);
	if(arg_list.flags & FLAG_DOT && arg_list.precision - (size_n - neg) > 0)
		size += spamotron ('0', arg_list.precision - (size_n - neg));
	if (arg_list.flags & FLAG_ZERO && !(arg_list.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron ('0', arg_list.min_field - size_n);
	size += write(1, array, size_n - neg);
	if(arg_list.flags & FLAG_MINUS && (arg_list.min_field - size) > 0)
		size += spamotron (' ', arg_list.min_field - size);
	free(array);
	return (size);
}

int		case_u(unsigned long long nb, t_format arg_list)
{
	int				size_n;
	int				size;
	char			*array;

	if(!(array = ft_u_itoa(nb)))
		return (-1);
	size = 0;
	size_n = ft_strlen (array);
	if(nb == 0 && arg_list.flags & FLAG_DOT && size_n > 0)
		size_n--;
	if (arg_list.flags & FLAG_DIGIT && arg_list.precision < size_n)
		size += spamotron(' ', arg_list.min_field - size_n);
	else if (arg_list.flags & (FLAG_DIGIT | FLAG_ZERO) && arg_list.flags & FLAG_DOT)
	{
		if(arg_list.precision >= size_n)
				size += spamotron(' ', arg_list.min_field - arg_list.precision);
			else
				size += spamotron(' ', arg_list.min_field - size_n);
	}
	if(arg_list.flags & FLAG_DOT && arg_list.precision - size_n > 0)
		size += spamotron ('0', arg_list.precision - size_n);
	if (arg_list.flags & FLAG_ZERO && !(arg_list.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron ('0', arg_list.min_field - size_n);
	size += write(1, array, size_n);
	if(arg_list.flags & FLAG_MINUS && (arg_list.min_field - size) > 0)
		size += spamotron (' ', arg_list.min_field - size);
	free(array);
	return (size);
}

int		case_x(unsigned long long nb, char c, t_format arg_list)
{
	int				size_n;
	int				size;
	char			*array;

	if(!(array = ft_itoabase(nb, 16)))
		return(-1);
	size = 0;
	size_n = ft_strlen(array);
	if(nb == 0 && arg_list.flags & FLAG_DOT && size_n > 0)
		size_n--;
	if (arg_list.flags & FLAG_DIGIT && arg_list.precision < size_n)
		size += spamotron(' ', arg_list.min_field - size_n);
	else if (arg_list.flags & (FLAG_DIGIT | FLAG_ZERO) && arg_list.flags & FLAG_DOT)
	{
		if(arg_list.precision > size_n)
			size += spamotron(' ', arg_list.min_field - arg_list.precision);
		else
			size += spamotron(' ', arg_list.min_field - size_n);
	}
	if(arg_list.flags & FLAG_DOT && arg_list.precision - size_n > 0)
		size += spamotron ('0', arg_list.precision - size_n);
	if (arg_list.flags & FLAG_ZERO && !(arg_list.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron ('0', arg_list.min_field - size_n);
	if(c == 'x' && (!(size_n == 0 && arg_list.flags & FLAG_DOT)))
		size += write(1, array, size_n);
	else if(!(nb == 0 && arg_list.flags & FLAG_DOT))
		size += write(1, ft_str_toupper(array), size_n);
	else
		write(1, 0, 1);
	if (arg_list.flags & FLAG_ZERO && arg_list.flags & FLAG_DOT)
		size += spamotron(' ', arg_list.min_field - size);
	if(arg_list.flags & FLAG_MINUS)
		size += spamotron(' ', arg_list.min_field - size);
	free(array);
	return (size);
}

int		case_prct(t_format arg_list)
{
	int				i;
	int				size;

	i = 0;
	size = 0;
	if (arg_list.flags & FLAG_DIGIT)
		size += spamotron(' ', arg_list.min_field - 1);
	if (arg_list.flags & FLAG_ZERO)
		size += spamotron('0', arg_list.min_field -1);
	size += write(1, "%", 1);
	if (arg_list.flags & FLAG_MINUS)
		size += spamotron(' ', arg_list.min_field - 1);
	return (size);
}
