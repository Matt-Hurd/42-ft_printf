/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:17:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 16:18:34 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	int x, y;
	// if (ac > 1)
	// 	ft_printf(av[1]);
	x = ft_printf("ABC %8.1s DEF %c test %hho\n", "HELLO", 0, -134);
	y = printf("ABC %8.1s DEF %c test %hho\n", "HELLO", 0, -134);
	return (0);
}
