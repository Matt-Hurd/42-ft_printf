#include "ft_printf.h"

void	ft_conv_n(char in, t_output *out, t_arg *flags, va_list *ap)
{
	int	*storage;

	(void)in;
	(void)flags;
	storage = va_arg(ap, int *);
	*storage = out->len;
}
