/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:58:46 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/14 11:38:45 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_c(int c, t_format *arg_list)
{
	int i;

	i = 0;
	if (arg_list->flags & FLAG_ZERO)
		i += spamotron('0', arg_list->min_field);
	
	return (write(1, &c, 1));
}

int		case_s(char *s)
{
	int		i;

	i = ft_putstrlen_fd(s, 1);
	return (i);
}

int		case_p(void *p)
{
	int		i;
	char	*array;

	i = 2;
	if(!(array = ft_itoabase((unsigned long long)p, 16)))
		return (-1);
	write(1, "0x", 2);
	i += ft_putstrlen_fd(array, 1);
	free(array);
	return (i);
}

int		case_d(int nb)
{
	int		i;
	char	*array;

	i = 0;
	if(!(array = ft_itoa(nb)))
		return(-1);
	i = ft_putstrlen_fd(array, 1);
	free(array);
	return(i);
}

int		case_u(unsigned long long nb)
{
	int		i;
	char	*array;

	if(!(array = ft_u_itoa(nb)))
		return (-1);
	i = ft_putstrlen_fd(array, 1);
	free(array);
	return (i);
}

int		case_x(unsigned long long nb, char c)
{
	int		i;
	char	*array;

	i = 0;
	if(!(array = ft_itoabase(nb, 16)))
		return(-1);
	if (c == 'X')
	while (array[i] != '\0')
	{
		array[i] = ft_toupper((char) array[i]);
		i++;
	}
	i = ft_putstrlen_fd(array, 1);
	free(array);
	return (i);
}

int		case_prct(void)
{
	char prct;

	prct = '%';
	return (write(1, &prct, 1));
}
