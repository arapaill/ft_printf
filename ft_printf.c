/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:14:25 by arapaill          #+#    #+#             */
/*   Updated: 2020/01/08 09:30:14 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		trieur(char c, const char *s)
{
	if (c == 'c')
		return (case_c(s));
	if (c == 's')
		return (case_s(s));
	if (c == 'p')
		return (case_p(s));
	if (c == 'd' || c == 'i')
		return (case_d(s));
	if (c == 'u')
		return (case_u(s));
	if (c == 'x' || c == 'X')
		return (case_x(s));
	if (c == '%')
		return (case_prct(s));
}

int				ft_printf(const char *s, ...)
{
	char	*array;
	int		i;

	i = ft_strchr_mod(s, '%');
	if (array = malloc(sizeof(char) * i + 1))
		return (0);
	array = ft_memcpy(array, s, i + 1);
	trieur(ft_strchr(s, '%'), s);
}
