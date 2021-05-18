/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:55:48 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/05/05 13:55:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_proc(unsigned long n, int capitals, size_t counter)
{
	char	*str;

	str = malloc(sizeof (char) * (counter + 1));
	if (!str)
		return (NULL);
	str[counter] = '\0';
	counter--;
	while (n != 0)
	{
		if (n % 16 >= 10)
		{
			if (capitals == 0)
				str[counter] = n % 16 + 87;
			else if (capitals == 1)
				str[counter] = n % 16 + 55;
		}
		else
			str[counter] = n % 16 + '0';
		n /= 16;
		counter--;
	}
	return (str);
}

static char	*proc_str_hex(unsigned long n, int capitals)
{
	size_t			counter;
	char			*str;
	unsigned long	tmp;

	if (n == 0)
	{
		str = ft_strdup("0");
		if (!str)
			return (NULL);
		return (str);
	}
	counter = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp /= 16;
		counter++;
	}
	str = str_proc(n, capitals, counter);
	if (!str)
		return (NULL);
	return (str);
}

static size_t	proc_hex_minus(t_flags flags, char *str)
{
	size_t	len;

	len = 0;
	if (flags.precision >= 0)
		len += add_width(flags.precision, ft_strlen(str), 1);
	len += put_str_with_precision(str, ft_strlen(str));
	return (len);
}

size_t	proc_hex(unsigned int n, int capitals, t_flags flags)
{
	char	*str;
	size_t	len;

	len = 0;
	n += 4294967295 + 1;
	if (flags.precision == 0 && n == 0)
		len += add_width(flags.width, 0, 0);
	if (flags.precision == 0 && n == 0)
		return (len);
	str = proc_str_hex((unsigned long)n, capitals);
	if (flags.minus == 1)
		len += proc_hex_minus(flags, str);
	if (flags.precision >= 0 && flags.precision < (int)ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		len += add_width(flags.width, 0, 0);
	}
	else
		len += add_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		len += proc_hex_minus(flags, str);
	free(str);
	return (len);
}
