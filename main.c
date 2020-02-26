/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:53:11 by arapaill          #+#    #+#             */
/*   Updated: 2020/02/26 16:06:15 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
   printf("----printf----\n");
   i = printf("'%2.9p'\n", 1234);
    printf("---ft_printf--\n");
    j = ft_printf("'%p'\n", NULL);
    printf("size printf : %i, size ft_printf : %i\n", i, j);
    return(0);
}
