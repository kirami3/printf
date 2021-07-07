#include "ft_printf.h"
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, str);
	flags.g_res = 0;
	ft_cleanflags(&flags);
	pars(str, ap, &flags);
	va_end(ap);
	return (flags.g_res);
}
