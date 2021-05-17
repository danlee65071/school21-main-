/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:08:35 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/28 17:08:37 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	start_prepare(char **start, char **line)
{
	char	*ptr_nl;

	if (*start)
	{
		ptr_nl = ft_strchr(*start, '\n');
		if (ptr_nl)
		{
			*ptr_nl = '\0';
			*line = ft_strdup(*start);
			ptr_nl++;
			ft_strlcpy(*start, ptr_nl, ft_strlen(ptr_nl) + 1);
			return (1);
		}
		*line = ft_strdup(*start);
		free(*start);
		*start = NULL;
	}
	else
	{
		*line = malloc(sizeof(char));
		if (!(*line))
			return (-1);
		**line = '\0';
	}
	return (0);
}

int	line_out(char **line, char **start, char *ptr_nl, char *buff)
{
	char	*tmp;

	*ptr_nl = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buff);
	free(tmp);
	*start = ft_strdup(++ptr_nl);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	size_t		qnty_els;
	char		*ptr_nl;
	char		*tmp;
	static char	*start;

	if (fd < 0 || fd > 19 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (start_prepare(&start, line) == 1)
		return (1);
	qnty_els = read(fd, buff, BUFFER_SIZE);
	while (qnty_els)
	{
		buff[qnty_els] = '\0';
		ptr_nl = ft_strchr(buff, '\n');
		if (ptr_nl)
			return (line_out(line, &start, ptr_nl, buff));
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
		qnty_els = read(fd, buff, BUFFER_SIZE);
	}
	return (0);
}
