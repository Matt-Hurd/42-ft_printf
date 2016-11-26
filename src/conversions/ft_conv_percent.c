#include "ft_printf.h"

//TODO: Wide chars

void	ft_conv_percent(char in, t_output *out, t_arg *flags, va_list *ap)
{
	(void)flags;
	(void)ap;
	(void)in;
	out->str = ft_strnjoin(out->str, out->len, "%", 1);
	out->len += 1;
}
