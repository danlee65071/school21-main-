#include "get_next_line.h"

char	*ft_strchr (const char *s, int c)
{
	char	*new_s;
	char	ch;

	new_s = (char *)s;
	ch = (char)c;
	if (ch == '\0')
	{
		while (*new_s)
			new_s++;
		return (new_s);
	}
	while (*new_s)
	{
		if (*new_s == ch)
			return (new_s);
		new_s++;
	}
	return (NULL);
}

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;
	int		cnt_s1;
	int		cnt_s2;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cnt_s1 = ft_strlen(s1);
	cnt_s2 = ft_strlen(s2);
	new_s = (char *) malloc(cnt_s1 + cnt_s2 + 1);
	if (new_s == NULL)
		return (NULL);
	while (s1[i] != '\0')
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_s[j++] = s2[i++];
	new_s[j] = '\0';
	return (new_s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_s[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*new;
	size_t	cnt;

	cnt = number * size;
	new = malloc(cnt);
	if (new == 0)
		return (0);
	ft_bzero(new, cnt);
	return (new);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '\0')
		i++;
	new_str = malloc(i + 1);
	if (new_str == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[cnt] != '\0')
		cnt++;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (cnt);
}
