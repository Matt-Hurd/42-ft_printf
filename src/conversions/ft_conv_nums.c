#include "ft_printf.h"

//TODO: Wide chars

void	handle_upper(char *str, char in)
{
	if (in != 'X')
		return ;
	while (*str)
	{
		if (ft_isalpha(*str))
			*str = ft_toupper(*str);
		str++;
	}
}

void	handle_alternative(char **str, t_arg *flags)
{
	if (!flags->alternative)
		return ;
	flags->pad_zeroes = 0;
	*str = ft_strjoin("0x", *str);
}

int		find_base(char in)
{
	if (in == 'o')
		return (8);
	else if (in == 'x' || in == 'X' || in == 'p')
		return (16);
	else if (in == 'b')
		return (2);
	else
		return (10);
}

int		find_sign(char in)
{
	if (in == 'd' || in == 'i')
		return (0);
	return (1);
}

void	ft_conv_nums(char in, t_output *out, t_arg *flags, va_list *ap)
{
	uintmax_t	num;
	char		*str;

	(void)in;
	if (in == 'p')
	{
		flags->alternative = 1;
		flags->length = l;
	}
	if (flags->length == hh)
		num = va_arg(ap, int);
	else if (flags->length == h)
		num = va_arg(ap, int);
	else if (flags->length == l)
		num = va_arg(ap, long);
	else if (flags->length == ll || flags->length == q)
		num = va_arg(ap, long long);
	else if (flags->length == z)
		num = va_arg(ap, size_t);
	else if (flags->length == j)
		num = va_arg(ap, intmax_t);
	else
		num = va_arg(ap, int);
	str = ft_num_to_base(num, find_base(in), find_sign(in), flags->length);
	handle_precision(&str, flags, 'd');
	handle_alternative(&str, flags);
	handle_padding(&str, flags, 'd');
	handle_upper(str, in);
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
}
