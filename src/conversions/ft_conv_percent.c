#include "ft_printf.h"

void	ft_conv_percent(char in, t_output *out, t_arg *flags, va_list *ap)
{
	(void)flags;
	(void)ap;
	(void)in;

	char	*str;
	str = ft_strnew(1);
	str[0] = in;
	handle_padding(&str, flags, '%');
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
}
