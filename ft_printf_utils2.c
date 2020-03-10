/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:09:40 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/09 12:11:08 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_arg(char c)
{
	int i;

	i = 0;
	if (c == 'c' || c == 's' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%' || c == 'p')
		return (1);
	return (0);
}

int				spamotron(char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}
