/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:03:23 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 14:57:23 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char		*ft_get_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(words);
	words = 0;
}

static char		**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;

	if (!s || !(str = ft_strdup((char *)s)))
		return (NULL);
	tab = ft_get_words(str, c, ft_count_words(str, c));
	free(str);
	return (tab);
}
