#include "ft_printf.h"

//TODO: Wide chars

int		find_base(char in)
{
	if (in == 'o')
		return (8);
	else if (in == 'x')
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
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
}
