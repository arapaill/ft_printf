/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:53:11 by arapaill          #+#    #+#             */
/*   Updated: 2020/03/10 11:31:49 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("----printf----\n");
	i = printf("'%p'\n", &i);
	printf("---ft_printf--\n");
	j = ft_printf("this %i number \n", 17);
	printf("size printf : %i, size ft_printf : %i\n", i, j);
	return (0);
}
