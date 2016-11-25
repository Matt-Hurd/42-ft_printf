#include "ft_printf.h"

//TODO: Wide chars

void	ft_conv_c(char in, t_output *out, t_arg *flags, va_list *ap)
{
	int		c;
	char	*str;
	char	null;
	size_t	len;
	size_t	pos;

	(void)in;
	c = va_arg(ap, int);
	str = ft_strnew(1);
	null = (c == 0) ? 1 : 0;
	str[0] = c + null;
	handle_padding(&str, flags, 's');
	if (null)
	{
		len = ft_strlen(str);
		pos = 0;
		while (pos < len)
		{
			if (str[pos] == null)
				str[pos] = 0;
			pos++;
		}
		out->str = ft_strnjoin(out->str, out->len, str, len);
		out->len += len;
	}
	else
	{
		out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
		out->len += ft_strlen(str);
	}
}
