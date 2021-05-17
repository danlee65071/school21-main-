/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:08:52 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/28 17:08:54 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len_s;

	if (!s)
		return (0);
	len_s = 0;
	while (s[len_s])
		len_s++;
	return (len_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_new_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_new_str = len_s1 + len_s2;
	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		new_str[i] = s1[i];
	i--;
	while (++i < len_new_str)
		new_str[i] = s2[i - len_s1];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != 0)
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	if (c == '\0')
		return (&tmp_s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	if (!dst || !src)
		return (0);
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*new_str;

	len_s1 = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (len_s1 + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	return (new_str);
}
