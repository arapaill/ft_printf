/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:54:53 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/13 16:45:27 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int lol;
	char c;

	c = 'a';
	lol = 42;
	printf("__PRINTF__:\nlol %u\nc : %c\n",lol, c);
	printf("______\n\n");
	ft_printf("FT_PRINTF :\nlol %u\nc : %c\n",lol, c);
	return(0);
}
