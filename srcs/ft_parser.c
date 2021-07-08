#include "ft_printf.h"

void	ft_arg(t_flags *flags, va_list ap, const char *str)
{
	if (*str == 's')
		ft_printf_s(va_arg(ap, char *), flags);
	else if (*str == 'c')
		ft_printf_c(va_arg(ap, int), flags);
	else if (*str == 'x')
		ft_printf_x(va_arg(ap, unsigned int), flags);
	else if (*str == 'X')
		ft_printf_X(va_arg(ap, unsigned int), flags);
	if (*str == 'd')
		ft_printf_d(va_arg(ap, int), flags);
	else if (*str == 'i')
		ft_printf_d(va_arg(ap, int), flags);
	else if (*str == 'u')
		ft_printf_u(va_arg (ap, unsigned int), flags);
	else if (*str == 'p')
		ft_printf_p(va_arg(ap, int *), flags);
}

void	pars_help(t_flags *flags)
{
	if (flags->g_dot == -1 && flags->g_zero == 0)
		flags->g_zero = 1;
	if (flags->g_zero == 0)
		flags->g_zero = -1;
}

void	pars(const char *str, va_list ap, t_flags *flags)
{
	while (*str)
	{
		if (*str == '%' && *(++str))
		{
			str += ft_zero_nul(str, flags);
			if (*str != '0')
				str += ft_width(flags, str);
			if (*str == '*')
				str += ft_star(flags, ap);
			if (*str == '.')
				str += ft_dot_star(flags, str, ap);
			pars_help(flags);
			if (*str == 's' || *str == 'c' || *str == 'x' || *str == 'X'
				|| *str == 'd' || *str == 'i' || *str == 'u' || *str == 'p')
				ft_arg(flags, ap, str);
			else
				ft_printf_c(*str, flags);
		}
		else
			ft_putchar(*str, flags);
		ft_cleanflags(flags);
		str++;
	}
}
