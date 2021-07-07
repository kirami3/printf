#include "ft_printf.h"
/*
static void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->g_res++;
}

static void	ft_putstr(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], flags);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}*/
/*
void	ft_cleanflags(t_flags *flags)
{
	flags->g_width = -1;
	flags->g_minus = -1;
	flags->g_dot = -1;
	flags->g_zero = -1;
}

void	ft_toch(const char *str, t_flags *flags)
{
	while (*str != 's' && *str != 'c' && *str != 'x'
		&& *str != 'X' && *str != 'd' && *str != 'i'
		&& *str != 'u' && *str != 'p' && *str != '\0')
	{
		if (*str == '.')
			flags->g_dot = 0;
		str++;
	}
}

int	ft_zero_nul(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
		{
			flags->g_minus = 1;
			if (flags->g_zero == 0)
				flags->g_zero = -1;
		}
		if (*str == '0' && flags->g_minus == -1)
			flags->g_zero = 0;
		str++;
		i++;
	}
	ft_toch(str, flags);
	return (i);
}

int	ft_width(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		flags->g_width = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			flags->g_width = flags->g_width *10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_dot_star(t_flags *flags, const char *str, va_list ap)
{
	int	i;

	i = 1;
	if (*(++str) == '*')
	{
		flags->g_dot = va_arg(ap, int);
		i += 1;
		if (flags->g_dot < 0 && flags->g_zero == 0)
		{
			flags->g_zero = 1;
			flags->g_dot = -1;
		}
	}
	if (*str >= '0' && *str <= '9')
	{	
		while (*str >= '0' && *str <= '9')
		{
			flags->g_dot = flags->g_dot * 10 + (*str - '0');
			str++;
			i++;
		}
		if (flags->g_zero == 0)
			flags->g_zero = -1;
	}
	return (i);
}

int	ft_star(t_flags *flags, va_list ap)
{
	int	i;

	i = 1;
	if (flags->g_width == -1)
	{
		flags->g_width = va_arg(ap, int);
		if (flags->g_width < 0)
		{
			flags->g_minus = 1;
			flags->g_width *= -1;
		}
	}
	return (i);
}
*/
/*
int	ft_helpitoa(int len, unsigned long t, int b)
{
	while (t > 0 )
	{
		t /= b;
		len++;
	}
	return (len);
}

static char	*ft_itoa(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	temp_nbr = nbr;
	len = 0;
	str = NULL;
	if (nbr == 0)
		len++;
	len = ft_helpitoa(len, temp_nbr, base);
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] = str[len - 1] + '0';
		nbr /= base;
		len--;
	}
	return (str);
}
*/
/*
void	ft_format_left(char *str, int len, t_flags *flags, int minus)
{
	if (minus == 1)
	{
		ft_putchar('-', flags);
		flags->g_width--;
	}
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
			flags->g_width--;
		}
	}
	if (len != 0 )
		ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_format_right_help(int minus, t_flags *flags, int len)
{
	if (minus == 1 && flags->g_width > 0)
		flags->g_width--;
	while (flags->g_width > len && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_format_right(char *str, int len, t_flags *flags, int minus)
{
	ft_format_right_help(minus, flags, len);
	if (minus == 1)
		ft_putchar('-', flags);
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
		}
	}
	if (flags->g_zero == 1)
	{
		while (flags->g_width > ft_strlen(str))
		{
			ft_putchar('0', flags);
			flags->g_width--;
		}
	}
	if (len != 0)
		ft_putstr(str, flags);
}

static void	ft_printf_d(long nbr, t_flags *flags)
{
	char	*str;
	int		minus;
	int		len;

	minus = 0;
	if (nbr < 0)
		minus = 1;
	if (nbr < 0)
		nbr *= -1;
	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if ((flags->g_dot > -1 && flags->g_dot > len)
		|| (nbr == 0 && flags->g_dot == 0))
	{
		len = flags->g_dot;
	}
	if (!(flags->g_width == -1 && flags->g_dot == 0 && nbr == 0 )
		&& !(flags->g_width == 0 && flags->g_dot == 0 && nbr == 0))
	{
		if (flags->g_minus == 1)
			ft_format_left(str, len, flags, minus);
		else
			ft_format_right(str, len, flags, minus);
	}
	free(str);
}

void	ft_swrite(t_flags *flags, char *str2)
{
	int	l;

	l = ft_strlen(str2);
	if (flags->g_dot > -1 && flags->g_dot < l)
		l = flags->g_dot;
	if ((flags->g_minus == 1 && flags->g_dot != 0 && str2))
		ft_putstr(str2, flags);
	while (flags->g_width > l)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	if (flags->g_minus == -1 && flags->g_dot != 0 && str2)
		ft_putstr(str2, flags);
}

void	ft_printf_s_help(t_flags *flags)
{
	int		m;
	int		i;
	char	*str2;
	char	*str3;
	char	*str4;

	i = 0;
	str4 = "(null)";
	str2 = (char *)malloc(7);
	str3 = str2;
	m = flags->g_dot;
	if (m > 6 || m <= 0)
		m = 6;
	while (m)
	{
		str2[i] = str4[i];
		i++;
		m--;
	}
	str2[i] = '\0';
	ft_swrite(flags, str2);
	free(str3);
}

void	ft_printf_s_help_1(t_flags *flags, char *str)
{
	char	*str2;

	if (!str)
		ft_printf_s_help(flags);
	else if (!(flags->g_dot > 0 && flags->g_dot < ft_strlen(str) && str))
	{
		str2 = str;
		ft_swrite(flags, str2);
	}
}

static void	ft_printf_s(char *str, t_flags *flags)
{
	int		m;
	char	*str3;
	char	*str2;
	int		i;

	str2 = (char *)malloc(ft_strlen(str) + 6);
	m = flags->g_dot;
	i = 0;
	str3 = str2;
	if (flags->g_dot > 0 && flags->g_dot < ft_strlen(str) && str)
	{
		while (m)
		{
			str2[i] = str[i];
			i++;
			m--;
		}
		str2[i] = '\0';
		ft_swrite(flags, str2);
	}
	ft_printf_s_help_1(flags, str);
	free(str3);
}
*/
/*
void	ft_pprint_left(t_flags *flags, char *str, int len)
{
	ft_putstr("0x", flags);
	while (len > ft_strlen(str))
	{
		ft_putchar('0', flags);
		len--;
	}
	ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_pprint_right(t_flags *flags, char *str, int len)
{
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0', flags);
		len--;
	}
	ft_putstr("0x", flags);
	ft_putstr(str, flags);
}

static void	ft_printf_p(int *nbr, t_flags *flags)
{
	char				*str;
	unsigned long int	c;
	int					len;

	c = (unsigned long int)nbr;
	str = ft_itoa(c, 16);
	len = ft_strlen(str);
	if (flags->g_dot > 0 && flags->g_dot > len)
		len = flags->g_dot;
	flags->g_width -= 2;
	if (flags->g_minus == -1)
		ft_pprint_right(flags, str, len);
	else
		ft_pprint_left(flags, str, len);
	free(str);
}
*/
/*
void	ft_uprint_right(t_flags *flags, char *str, int len, int nbr)
{
	while (flags->g_width > len && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
		}
	}
	if (flags->g_zero == 1)
	{
		while (flags->g_width > ft_strlen(str))
		{
			ft_putchar('0', flags);
			flags->g_width--;
		}
	}
	if (!(nbr == 0 && flags->g_dot == 0) && len != 0)
		ft_putstr(str, flags);
}

void	ft_uprint_left(t_flags *flags, char *str, int len, int nbr)
{
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
			flags->g_width--;
		}
	}
	if (!(nbr == 0 && flags->g_dot == 0) && len != 0)
		ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

int	ft_dlina_nbr(int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	ft_printf_u(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if (flags->g_dot > -1 && flags->g_dot > ft_strlen(str))
		len = flags->g_dot;
	if (flags->g_dot == 0 && nbr == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}*/
/*
void	ft_cprint_right(t_flags *flags, int c)
{
	while (flags->g_width > 1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	ft_putchar(c, flags);
}

void	ft_cprint_left(t_flags *flags, int c)
{
	ft_putchar(c, flags);
	while (flags->g_width > 1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

static void	ft_printf_c(int c, t_flags *flags)
{
	if (flags->g_minus == 1)
		ft_cprint_left(flags, c);
	else
		ft_cprint_right(flags, c);
}
*/
/*
static void	ft_printf_x(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr, 16);
	len = ft_strlen(str);
	if (flags->g_dot != -1 && flags->g_dot > len)
		len = flags->g_dot;
	if (nbr == 0 && flags->g_dot == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}

static void	ft_printf_X(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = NULL;
	str = ft_itoa(nbr, 16);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 32;
		i++;
	}
	len = ft_strlen(str);
	if (flags->g_dot != -1 && flags->g_dot > len)
		len = flags->g_dot;
	if (nbr == 0 && flags->g_dot == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}*/
/*
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
*/
/*
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
				ft_putchar(*str, flags);
		}
		else
			ft_putchar(*str, flags);
		ft_cleanflags(flags);
		str++;
	}
}
*/
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
/*
int	main()
{
	printf("[%-9.1s]\n", NULL);
	ft_printf("[%-9.1s]\n", NULL);

	return (0);
}*/
