/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:58:36 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/09 13:43:08 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			len_digit(long nb)
{
	int				l;

	l = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 16;
		l++;
	}
	return (l);
}

static char			*ft_zero(void)
{
	char			*str;

	str = ft_calloc(1, sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = 48;
	str[1] = '\0';
	return (str);
}

char				*ft_itoabase(unsigned int n)
{
	char			*str;
	long			nb;
	int				i;
	char			*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (ft_zero());
	if (!n)
		return (NULL);
	nb = n;
	i = len_digit(n);
	if (!(str = (char*)ft_calloc(1, sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (nb > 0)
	{
		str[i] = tab[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}

char				*ft_u_itoa(unsigned long long nb)
{
	unsigned long long	tmp;
	int					i;
	char				*ret;

	tmp = nb;
	i = 0;
	if (nb == 0)
		return (ft_zero());
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	if (!(ret = ft_calloc(1, sizeof(char) * (i + 1))))
		return (NULL);
	ret[i + 1] = '\0';
	while (nb > 0)
	{
		ret[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

char				*ft_llu_itoabase(long long unsigned i, char *base)
{
	long long unsigned	cpy_i;
	size_t				size_base;
	size_t				n;
	char				*result;

	n = 0;
	cpy_i = i;
	size_base = ft_strlen(base);
	while (cpy_i > 0)
	{
		n++;
		cpy_i /= size_base;
	}
	if (i == 0)
		n = 1;
	if (!(result = malloc(sizeof(char) * n + 1)))
		return (NULL);
	result[n--] = '\0';
	(i == 0) ? result[0] = '0' : 0;
	while (i > 0)
	{
		result[n--] = base[i % size_base];
		i /= size_base;
	}
	return (result);
}
