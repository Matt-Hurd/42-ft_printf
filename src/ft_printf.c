/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:28:58 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/26 19:35:57 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"





/* ************************************************************************** */
#include <stdio.h>
/* ************************************************************************** */



char	*g_convs = "diouxXDOUeEfFgGaACcSspn%";

t_conv g_convtab[] =
{
	{"d", &ft_conv_unimp},
	{"i", &ft_conv_unimp},
	{"o", &ft_conv_unimp},
	{"u", &ft_conv_unimp},
	{"x", &ft_conv_unimp},
	{"X", &ft_conv_unimp},
	{"D", &ft_conv_unimp},
	{"O", &ft_conv_unimp},
	{"U", &ft_conv_unimp},
	{"e", &ft_conv_unimp},
	{"E", &ft_conv_unimp},
	{"f", &ft_conv_unimp},
	{"F", &ft_conv_unimp},
	{"g", &ft_conv_unimp},
	{"G", &ft_conv_unimp},
	{"a", &ft_conv_unimp},
	{"A", &ft_conv_unimp},
	{"C", &ft_conv_unimp},
	{"c", &ft_conv_unimp},
	{"S", &ft_conv_unimp},
	{"s", &ft_conv_unimp},
	{"p", &ft_conv_unimp},
	{"n", &ft_conv_unimp},
	{"%", &ft_conv_unimp}
};

char	*do_conversion(char **in, va_list ap, unsigned int len)
{
	char	*ret;
	int		i;
	int		conv_count;
	int		pos_in_tab;


	i = -1;
	pos_in_tab = ft_strchr(g_convs, (*in)[len]) - g_convs;
	ret = g_convtab[pos_in_tab].ft(*in, len, ap);
	*in += len + 1;
	return (ret);
}

char	*get_next_string(char **in, va_list ap)
{
	char			*tmp;
	unsigned int	len;
	long			dist;

	tmp = *in;
	dist = ft_strchr(tmp, '%') - tmp;
	if (dist > 0)
	{
		*in += dist;
		return (ft_strncpy(ft_strnew(dist), tmp, dist));
	}
	else if (dist == -(long)tmp)
	{
		*in = ft_strchr(*in, '\0');
		return (ft_strdup(tmp));
	}
	tmp++;
	while (*tmp && !ft_strchr(g_convs, *tmp))
		tmp++;
	if (*tmp)
		return (do_conversion(in, ap, tmp - *in));
	else
		return (NULL);
}

long	count_strings(char *in)
{
	long	ct;
	char	*tmp;

	ct = 0;
	tmp = in;
	while (*tmp)
	{
		while (*tmp != '%' && *tmp)
			tmp++;
		if (in != tmp)
			ct++;
		if (*tmp == '%')
		{
			in = ++tmp;
			while (*tmp && !ft_strchr(g_convs, *tmp))
				tmp++;
			ct++;
			if (*tmp)
				in = ++tmp;
			else
				return (-1);
		}
	}
	return (ct);
}

void	ft_printf(char *in, ...)
{
	va_list	ap;
	va_list	ap2;
	char	**out_buff;
	long	out_count;

	va_start(ap, in);
	va_copy(ap2, ap);
	out_count = count_strings(in);
	out_buff = (char **)ft_memalloc(sizeof(char *) * out_count);
	printf("%s, %d\n", in, (int)count_strings(in));
	while (*in)
	{
/* ************************************************************************** */
		printf("%s\n", get_next_string(&in, ap));
/* ************************************************************************** */
	}
}

/* ************************************************************************** */
int		main(int ac, char **av)
{
	if (ac == 2)
		ft_printf(av[1]);
	printf("%9s", "a");
}
/* ************************************************************************** */
