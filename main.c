/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:17:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 10:55:17 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <locale.h>

int		main(int ac, char **av)
{
	int x, y;

	setlocale(LC_ALL, "");
	x = 0;
	y = 0;
	// x = ft_printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	// y = printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	ft_printf("%.0p\n", 0);
	printf("%.0p\n", 0);
	return (0);
}
