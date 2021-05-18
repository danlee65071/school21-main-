#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
}		t_flags;

int		ft_printf(const char *format, ...);
int		parse_input(char *format, va_list arguments);
void	flags_init(t_flags *flags);
size_t	parse_flags(char *format, size_t i, t_flags *flags, va_list arguments);
int		is_type(int c);
size_t	processor(char type, t_flags flags, va_list arguments);
void	flag_dot(char *format, size_t *i, t_flags *flags, va_list arguments);
void	flag_minus(t_flags *flags);
void	flag_width(va_list arguments, t_flags *flags);
void	flag_digit(char c, t_flags *flags);
size_t	add_width(int width, int minus, int is_zero);
size_t	proc_char(char c, t_flags flags);
size_t	proc_string(char *s, t_flags *flags);
size_t	put_str_with_precision(char *str, int precision);
size_t	proc_pointer(unsigned long n, t_flags flags);
size_t	proc_int(int n, t_flags flags);
char	*itoa_u(unsigned int n);
size_t	proc_uint(unsigned int n, t_flags flags);
size_t	proc_hex(unsigned int n, int capitals, t_flags flags);
size_t	proc_percent(t_flags flags);

#endif
