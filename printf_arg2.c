/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:58:35 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/10 11:37:25 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		case_x_nxt(char c, t_format form, char *array, size_t nb)
{
	int				size;
	int				size_n;

	size = 0;
	size_n = ft_strlen(array);
	nb == 0 && form.flags & FLAG_DOT && size_n > 0 ? size_n-- : 0;
	if (form.flags & FLAG_DIGIT && form.precision < size_n)
		size += spamotron(' ', form.min_field - size_n);
	else if (form.flags & (FLAG_DIGIT | FLAG_ZERO) && form.flags & FLAG_DOT)
		size += form.precision > size_n ? spamotron(' ', form.min_field -
		form.precision) : spamotron(' ', form.min_field - size_n);
	if (form.flags & FLAG_DOT && form.precision - size_n > 0)
		size += spamotron('0', form.precision - size_n);
	if (form.flags & FLAG_ZERO && !(form.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron('0', form.min_field - size_n);
	if (c == 'x' && (!(size_n == 0 && form.flags & FLAG_DOT)))
		size += ft_putstrlen_fd(array, 1);
	else if (!(nb == 0 && form.flags & FLAG_DOT))
		size += write(1, ft_str_toupper(array), size_n);
	else
		write(1, 0, 1);
	size += spamotron(' ', form.min_field - size);
	free(array);
	return (size);
}

int				case_x(size_t nb, char c, t_format form)
{
	char			*array;

	if (!(array = ft_itoabase(nb)))
		return (-1);
	return (case_x_nxt(c, form, array, nb));
}

static int		arg_d_nxt(int size_i, short neg, t_format form,
					char *itoa_i)
{
	int				size;

	size = 0;
	if (form.flags & FLAG_DIGIT && form.precision < size_i)
		size += spamotron(' ', form.min_field - size_i);
	else if (form.flags & (FLAG_DIGIT | FLAG_ZERO) && form.flags & FLAG_DOT)
		size += form.precision >= size_i ? spamotron(' ', form.min_field -
		(form.precision + neg)) : spamotron(' ', form.min_field - size_i);
	if (neg == 1)
		size += write(1, "-", 1);
	if (form.flags & FLAG_DOT && form.precision - (size_i - neg) > 0)
		size += spamotron('0', form.precision - (size_i - neg));
	if (form.flags & FLAG_ZERO && !(form.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron('0', form.min_field - size_i);
	size += write(1, itoa_i, size_i - neg);
	if (form.flags & FLAG_MINUS && (form.min_field - size) > 0)
		size += spamotron(' ', form.min_field - size);
	free(itoa_i);
	return (size);
}

int				arg_d(signed long int nb, t_format form)
{
	int				size;
	int				size_i;
	long long int	i;
	int				neg;
	char			*itoa_i;

	i = nb;
	neg = (i < 0) ? 1 : 0;
	i = (i < 0) ? i * -1 : i;
	if (!(itoa_i = ft_ll_itoa(i)))
		return (-1);
	size = 0;
	size_i = ft_strlen(itoa_i) + neg;
	if (i == 0 && form.flags & FLAG_DOT && size_i > 0)
		size_i--;
	return (size += arg_d_nxt(size_i, neg, form, itoa_i));
}
