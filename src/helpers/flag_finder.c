/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:08:46 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 17:53:00 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_width_precision(char *in, int len, t_arg *ret)
{
	int x;

	x = -1;
	while (++x < len)
	{
		if (in[x] != '0' && ft_isdigit(in[x]) && in[x - 1] != '.')
		{
			ret->got_width = 1;
			ret->width = ft_atoi(in + x);
		}
		if (in[x] == '.')
		{
			ret->got_precision = 1;
			ret->precision = ft_atoi(in + x + 1);
		}
	}
}

void	find_length(char *in, int len, t_arg *ret)
{
	int	x;

	x = -1;
	ret->length = none;
	while (++x < len && ret->length == none)
	{
		if (in[x] == 'h' && in[x + 1] == 'h')
			ret->length = hh;
		else if (in[x] == 'h')
			ret->length = h;
		else if (in[x] == 'l' && in[x + 1] == 'l')
			ret->length = ll;
		else if (in[x] == 'l')
			ret->length = l;
		else if (in[x] == 'L')
			ret->length = L;
		else if (in[x] == 'q')
			ret->length = q;
		else if (in[x] == 'j')
			ret->length = j;
		else if (in[x] == 'z')
			ret->length = z;
		else if (in[x] == 't')
			ret->length = t;
	}
}

t_arg	*find_flags(char *in, int len)
{
	t_arg	*ret;
	int		x;

	x = -1;
	ret = (t_arg *)ft_memalloc(sizeof(t_arg));
	while (++x < len)
	{
		if (in[x] == '#')
			ret->alternative = 1;
		if (in[x] == '0' && in[x - 1] != '.' && !ft_isdigit(in[x - 1]))
			ret->pad_zeroes = 1;
		if (in[x] == '-')
			ret->left_justify = 1;
		if (in[x] == ' ')
			ret->blank_sign = 1;
		if (in[x] == '+')
			ret->force_sign = 1;
		if (in[x] == '\'')
			ret->grouping = 1;
	}
	find_width_precision(in, len, ret);
	find_length(in, len, ret);
	return (ret);
}