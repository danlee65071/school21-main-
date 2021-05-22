#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_flags
{
	int width;
	int precision;
}	t_flags;

int parse_input(char *format, va_list arg);
void init_flags(t_flags *flags);
int format_percent(char *format, t_flags *flags, va_list arg, int *i);
int parse_flags(char *format, va_list arg, t_flags *flags, int i);
int is_type(char c);
int is_digit(char c);
void flag_dot(char *format, va_list arg, t_flags *flags, int *i);
int processor(char type, t_flags flags, va_list arg);
int ft_strlen(char *s);
int add_width(int width, int minus);
int put_str(char *str, int precision);
int proc_str(t_flags flags, char *s);
int proc_d(t_flags flags, int d);
char *ft_itoa(int n);
char *hex_itoa(unsigned int n);
int proc_hex(t_flags flags, unsigned int n);

int ft_printf(char *format, ...)
{
	va_list arg;
	int len;

	va_start(arg, format);
	len = 0;
	len += parse_input(format, arg);
	va_end(arg);
	return (len);
}

int parse_input(char *format, va_list arg)
{
	t_flags flags;
	int len;
	int i;

	len = 0;
	i = 0;
	while(1)
	{
		init_flags(&flags);
		if (format[i] == '\0')
			break ;
		if (format[i] == '%')
			len += format_percent(format, &flags, arg, &i);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int format_percent(char *format, t_flags *flags, va_list arg, int *i)
{
	int len = 0;

	if (format[*i + 1] == ' ')
	{
		write(1, " ", 1);
		len++;
		(*i)++;
	}
	*i = parse_flags(format, arg, flags, ++(*i));
	if (is_type(format[*i]))
		len += processor(format[*i], *flags, arg);
	return (len);
}

int processor(char type, t_flags flags, va_list arg)
{
	int len = 0;

	if (type == 's')
		len = proc_str(flags, va_arg(arg, char *));
	else if (type == 'd')
		len = proc_d(flags, va_arg(arg, int));
	else if (type == 'x')
		len = proc_hex(flags, va_arg(arg, unsigned int));
	return (len);
}

int proc_hex(t_flags flags, unsigned int n)
{
	int len = 0;
	char *str;

	str = hex_itoa(n);
	len = proc_str(flags, str);
	free(str);
	return (len);
}

int proc_d(t_flags flags, int d)
{
	int len = 0;
	char *str;

	str = ft_itoa(d);
	len = proc_str(flags, str);
	free(str);
	return (len);
}

int proc_str(t_flags flags, char *s)
{
	int len = 0;

	if (!s)
		s = "(null)";
	if (flags.precision >= 0 && flags.precision > ft_strlen(s))
		flags.precision = ft_strlen(s);
	if (flags.precision >= 0)
		len += add_width(flags.width, flags.precision);
	else
		len += add_width(flags.width, ft_strlen(s));
	if (flags.precision >= 0)
	{
		len += add_width(flags.precision, ft_strlen(s));
		len += put_str(s, flags.precision);
	}
	else
		len += put_str(s, ft_strlen(s));
	return (len);
}

int parse_flags(char *format, va_list arg, t_flags *flags, int i)
{
	while (format[i])
	{
		if (format[i] == '*')
			flags->width = va_arg(arg, int);
		if (format[i] == '.')
			flag_dot(format, arg, flags, &i);
		if (is_digit(format[i]))
			flags->width = flags->width * 10 + format[i] - '0';
		if (is_type(format[i]))
			break;
		i++;
	}
	return (i);
}

void flag_dot(char *format, va_list arg, t_flags *flags, int *i)
{
	++(*i);
	if (format[*i] == '*')
	{
		flags->precision = va_arg(arg, int);
		++(*i);
	}
	else
	{
		flags->precision = 0;
		while (is_digit(format[*i]))
		{
			flags->precision = flags->precision * 10 + format[*i] - '0';
			(*i)++;
		}
	}
}

void init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
}

int is_type(char c)
{
	return ((c == 's') || (c == 'd') || (c == 'x'));
}

int is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int ft_strlen(char *s)
{
	int len_s = 0;

	while (s[len_s])
		len_s++;
	return (len_s);
}

int add_width(int width, int minus)
{
	int len = 0;

	while (width - minus > 0)
	{
		write(1, " ", 1);
		width--;
		len++;
	}
	return (len);
}

int put_str(char *str, int precision)
{
	int len = 0;

	while (str[len] && len < precision)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	long tmp;
	int sign = 1;
	int len_n = 0;
	char *s;
	int i = 0;

	if (n < 0)
	{
		sign = -1;
		tmp = (-1) * n;
	}
	else
		tmp = n;
	while (n > 0)
	{
		len_n++;
		n /= 10;
	}
	if (sign == -1)
		len_n++;
	s = malloc(sizeof(char) * (len_n + 1));
	s[len_n] = '\0';
	if (sign == -1)
		s[0] = -1;
	if (tmp == 0)
		s[0] = '0';
	len_n--;
	while (tmp > 0)
	{
		s[len_n] = tmp % 10 + '0';
		len_n--;
		tmp /= 10;
	}
	return (s);
}

char *hex_itoa(unsigned int n)
{
	char *s;
	unsigned int tmp = n;
	int len_n = 0;

	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (tmp > 0)
	{
		len_n++;
		tmp /= 16;
	}
	s = malloc(sizeof(char) * (len_n + 1));
	s[len_n] = '\0';
	len_n--;
	while (n > 0)
	{
		if (n % 16 >= 10)
			s[len_n] = n % 16 + 87;
		else
			s[len_n] = n % 16 + '0';
		n /= 16;
		len_n--;
	}
	return (s);
}