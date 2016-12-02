/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:17:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/01 22:26:38 by mhurd            ###   ########.fr       */
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
	x = ft_printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	y = printf("%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	printf("%d, %d\n", x, y);
	return (0);
}
