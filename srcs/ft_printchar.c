#include "ft_printf.h"

void	ft_cprint_right(t_flags *flags, int c)
{
	while (flags->g_width > 1 && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	while (flags->g_width > 1 && flags->g_zero == 1)
	{
		ft_putchar('0', flags);
		flags->g_width--;
	}
	ft_putchar(c, flags);
}

void	ft_cprint_left(t_flags *flags, int c)
{
	ft_putchar(c, flags);
	while (flags->g_width > 1 && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	while (flags->g_width > 1 && flags->g_zero == 1)
	{
		ft_putchar('0', flags);
		flags->g_width--;
	}
}

void	ft_printf_c(int c, t_flags *flags)
{
	if (flags->g_minus == 1)
		ft_cprint_left(flags, c);
	else
		ft_cprint_right(flags, c);
}
