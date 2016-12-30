/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:17:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/30 11:06:14 by mhurd            ###   ########.fr       */
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
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');
	return (0);
}
