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
			if (ret->got_width)
			{
				ret->invalid = 1;
				return ;
			}
			ret->got_width = 1;
			ret->width = ft_atoi(in + x);
			while (in[x] && ft_isdigit(in[x++]))
				x++;
		}
		if (in[x] == '.' && in[x + 1] != '*')
		{
			if (ret->got_precision)
			{
				ret->invalid = 1;
				return ;
			}
			ret->got_precision = 1;
			ret->precision = ft_atoi(in + x + 1);
			while (in[x] && ft_isdigit(in[x++]))
				x++;
		}
	}
}

void	find_length(char *in, int len, t_arg *ret)
{
	int	x;
	int found;

	x = -1;
	ret->length = none;
	found = 0;
	while (++x < len)
	{
		if (in[x] == 'h' && in[x + 1] == 'h')
			ret->length = hh;
		else if (in[x] == 'h' && in[x - 1] != 'h')
			ret->length = h;
		else if (in[x] == 'l' && in[x + 1] == 'l')
			ret->length = ll;
		else if (in[x] == 'l' && in[x - 1] != 'l')
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
		else
			continue ;
		if (found)
		{
			ret->invalid = 1;
			return ;
		}
		found = 1;
	}
}

void	find_asterisk(char *in, t_arg *ret, va_list *ap)
{
	int x;
	int found;

	x = -1;
	while (in[++x])
	{
		if (in[x] == '*')
		{
			if (in[x - 1] == '.')
			{
				if (ret->got_precision)
				{
					ret->invalid = 1;
					return ;
				}
				found = va_arg(ap, int);
				if (found >= 0)
				{
					ret->precision = found;
					ret->got_precision = 1;
				}
			}
			else
			{
				if (ret->got_width)
				{
					ret->invalid = 1;
					return ;
				}
				found = va_arg(ap, int);
				if (found < 0)
					ret->left_justify = 1;
				ret->width = ABS(found);
				ret->got_width = 1;
			}
		}
	}
}

char	*g_valid = "diouxXDOUeEfFgGaACcSspn%Z.+-#0123456789\' *hlLqjzt";

t_arg	*find_flags(char *in, int len, va_list *ap)
{
	t_arg	*ret;
	int		x;

	x = -1;
	ret = (t_arg *)ft_memalloc(sizeof(t_arg));
	while (++x < len)
	{
		if (!ft_strchr(g_valid, in[x]))
		{
			ret->invalid = 1;
			return ret;
		}
		if (in[x] == '#')
		{
			if (ret->alternative)
				ret->invalid = 1;
			ret->alternative = 1;
		}
		if (in[x] == '0' && in[x - 1] != '.' && !ft_isdigit(in[x - 1]))
		{
			if (ret->pad_zeroes)
				ret->invalid = 1;
			ret->pad_zeroes = 1;
		}
		if (in[x] == '-')
		{
			if (ret->left_justify)
				ret->invalid = 1;
			ret->left_justify = 1;
		}
		if (in[x] == ' ')
		{
			if (ret->blank_sign)
				ret->invalid = 1;
			ret->blank_sign = 1;
		}
		if (in[x] == '+')
		{
			if (ret->force_sign)
				ret->invalid = 1;
			ret->force_sign = 1;
		}
		if (in[x] == '\'')
		{
			if (ret->grouping)
				ret->invalid = 1;
			ret->grouping = 1;
		}
	}
	find_width_precision(in, len, ret);
	find_asterisk(in, ret, ap);
	find_length(in, len, ret);
	return (ret);
}