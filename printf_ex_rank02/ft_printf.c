#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_flags
{
	int width;
	int precision;
}		t_flags;

static int parse_input(char *format, va_list argument);
static void flags_init(t_flags *flags);
static int parse_flags(char *format, t_flags *flags, int i);
static int flag_dot(char *format, t_flags *flags, int i);
static int is_digit(char c);
static void flag_width(char c, t_flags *flags);
static int is_type(char c);
static int processor(char type, t_flags flags, va_list argument);
static int proc_str(char *s, t_flags flags);
static int ft_strlen(char *s);
static int proc_str(char *s, t_flags flags);
static int put_str(char *s, int precision);
static int add_width(int width, int minus);

int ft_printf(char *format, ...)
{
	va_list arg;
	int len;

	len = 0;
	va_start(arg, format);
	len = parse_input(format, arg);
	va_end(arg);
	return (len);
}

static int parse_input(char *format, va_list argument)
{
	int len;
	int i;
	t_flags flags;

	len = 0;
	i = 0;
	while (1)
	{
		flags_init(&flags);
		if (!format[i])
			break;
		if (format[i] == '%')
		{
			i = parse_flags(format, &flags, ++i);
			if (is_type(format[i]))
				len += processor(format[i], flags, argument);
		}
		i++;
	}
	return (len);
}

static void flags_init(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
}

static int parse_flags(char *format, t_flags *flags, int i)
{
	while (format[i])
	{
		if (format[i] == '.')
			i = flag_dot(format, flags, i);
		if (is_digit(format[i]))
			flag_width(format[i], flags);
		if (is_type(format[i]))
			break;
		i++;
	}
	return (i);
}

static int flag_dot(char *format, t_flags *flags, int i)
{
	i++;
	flags->precision = 0;
	while (is_digit(format[i]))
	{
		flags->precision = flags->precision * 10 + format[i] - '0';
		i++;
	}
	return (i);
}

static int is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

static void flag_width(char c, t_flags *flags)
{
	if (is_digit(c))
		flags->width = flags->width * 10 + c -'0';
}

static int is_type(char c)
{
	return ((c == 's') || (c == 'd') || (c == 'x'));
}

static int processor(char type, t_flags flags, va_list argument)
{
	int len;

	len = 0;
	if (type == 's')
		len += proc_str(va_arg(argument, char *), flags);
	else if (type == 'd')
		len += proc_int();
	return (len);
}

static int proc_str(char *s, t_flags flags)
{
	int len;

	len = 0;
	if (!s)
		s = "null";
	if (flags.precision >= 0 && flags.precision > ft_strlen(s))
		flags.precision = ft_strlen(s);
	if (flags.precision >= 0)
	{
		len += add_width(flags.width, flags.precision);
		len += put_str(s, flags.precision);
	}
	else
	{
		len += add_width(flags.width, ft_strlen(s));
		len += put_str(s, ft_strlen(s));
	}
	return (len);
}

static int proc_int(int n, t_flags flags)
{
	int len;

	len = 0;

	return (len);
}

static int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int add_width(int width, int minus)
{
	int len;

	len = 0;
	while (width - minus > 0)
	{
		write(1, " ", 1);
		width--;
	}
	return (len);
}

static int put_str(char *s, int precision)
{
	int len;

	len = 0;
	while (s[len] && len < precision)
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}