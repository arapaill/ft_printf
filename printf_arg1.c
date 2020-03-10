/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:58:46 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/10 10:45:59 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_c(int c, t_format form)
{
	int				size;

	size = 0;
	if (form.flags & FLAG_ZERO)
		size += spamotron('0', form.min_field - 1);
	if (form.flags & FLAG_DIGIT)
		size += spamotron(' ', form.min_field - 1);
	size += write(1, &c, 1);
	if (form.flags & FLAG_MINUS)
		size += spamotron(' ', form.min_field - 1);
	return (size);
}

int		case_s(char *s, t_format form)
{
	int				size_s;
	int				size;
	int				mem;

	size = 0;
	mem = 0;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		mem = 1;
	}
	size_s = ft_strlen(s);
	if (form.flags & FLAG_DOT && form.precision < (int)ft_strlen(s))
		size_s = form.precision;
	if (form.flags & FLAG_DIGIT)
		size += spamotron(' ', form.min_field - size_s);
	if (form.flags & FLAG_ZERO)
		size += spamotron('0', form.min_field - size_s);
	size += form.flags & FLAG_DOT && form.precision < (int)ft_strlen(s) ?
		write(1, s, form.precision) : write(1, s, ft_strlen(s));
	if (form.flags & FLAG_MINUS && size_s < form.min_field)
		size += spamotron(' ', form.min_field - size_s);
	if (mem == 1)
		free(s);
	return (size);
}

int		case_p(long long unsigned adress, t_format form)
{
	int				size_tmp;
	int				size;
	char			*hexa_adress;

	hexa_adress = ft_llu_itoabase(adress, "0123456789abcdef");
	size = 0;
	size_tmp = ft_strlen(hexa_adress);
	if (adress == 0 && form.flags & FLAG_DOT && size_tmp > 0)
		size_tmp--;
	if (form.flags & FLAG_DIGIT)
		size += spamotron(' ', form.min_field - (size_tmp + 2));
	size += write(1, "0x", 2);
	if (form.flags & FLAG_DOT)
		size += spamotron('0', form.precision - size_tmp);
	if (form.flags & FLAG_ZERO)
		size += spamotron('0', form.min_field - size_tmp - 2);
	size += write(1, hexa_adress, size_tmp);
	if (form.flags & FLAG_MINUS && size_tmp < form.min_field)
		size += spamotron(' ', form.min_field - (size_tmp + 2));
	free(hexa_adress);
	return (size);
}

int		case_u(unsigned int i, t_format form)
{
	int				size_i;
	int				size;
	char			*itoa_i;

	if (!(itoa_i = ft_u_itoa(i)))
		return (-1);
	size_i = ft_strlen(itoa_i);
	size = 0;
	if (i == 0 && form.flags & FLAG_DOT && size_i > 0)
		size_i--;
	if (form.flags & FLAG_DIGIT && form.precision < size_i)
		size += spamotron(' ', form.min_field - size_i);
	else if (form.flags & (FLAG_DIGIT | FLAG_ZERO) && form.flags & FLAG_DOT)
		(form.precision > size_i) ? (size +=
		spamotron(' ', form.min_field - form.precision))
		: (size += spamotron(' ', form.min_field - (size_i)));
	if (form.flags & FLAG_ZERO && !(form.flags & (FLAG_DOT | FLAG_MINUS)))
		size += spamotron('0', form.min_field - size_i);
	if (form.flags & FLAG_DOT && form.precision - size_i > 0)
		size += spamotron('0', form.precision - size_i);
	size += write(1, itoa_i, size_i);
	if (form.flags & FLAG_MINUS && (form.min_field - size) > 0)
		size += spamotron(' ', form.min_field - size);
	free(itoa_i);
	return (size);
}

int		case_prct(t_format form)
{
	int				i;
	int				size;

	i = 0;
	size = 0;
	if (form.flags & FLAG_DIGIT)
		size += spamotron(' ', form.min_field - 1);
	if (form.flags & FLAG_ZERO)
		size += spamotron('0', form.min_field - 1);
	size += write(1, "%", 1);
	if (form.flags & FLAG_MINUS)
		size += spamotron(' ', form.min_field - 1);
	return (size);
}
