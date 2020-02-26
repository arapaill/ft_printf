/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:58:36 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/26 14:00:59 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digit(int nb, int base)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb % base;
		nb /= base;
		i++;
	}
	return (1);
}

static char		*if_zero(void)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (2))))
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char			*ft_itoabase(unsigned long long nb, int base)
{
	int		i;
	int		j;
	char	*array;
	char	buf;

	i = 0;
	j = 0;
	if (nb == 0)
		return (if_zero());
	if (!(array = malloc(sizeof(char *) * count_digit(nb, base) + 1)))
		return (NULL);
	array[count_digit(nb, base) + 1] = '\0';
	while (nb > 0)
	{
		array[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		i++;
	}
	i--;
	while (i > j)
	{
		buf = array[i];
		array[i--] = array[j];
		array[j++] = buf;
	}
	return (array);
}

char			*ft_u_itoa(unsigned long long nb)
{
	unsigned long long	tmp;
	int					i;
	char				*ret;

	tmp = nb;
	i = 0;
	if (nb == 0)
		return (if_zero());
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i + 1] = '\0';
	while (nb > 0)
	{
		ret[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

int				is_arg(char c)
{
	int i;

	i = 0;
	if (c == 'c' || c == 's' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
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
