#include "get_next_line.h"

char	*check_ost(char *ost, char **line)
{
	char	*point;

	point = NULL;
	if (ost)
	{
		point = ft_strchr(ost, '\n');
		if (point != NULL)
		{
			*point = '\0';
			*line = ft_strdup(ost);
			point++;
			ft_strlcpy(ost, point, ft_strlen(point) + 1); //ft_strcpy(ost,
			// point);
		}
		else
		{
			*line = ft_strdup(ost);
			//ft_strclr(ost);
			ost = NULL;
		}
	}
	else
	{
		*line = ft_strdup("");
	}
	return (point);
}

int	get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	int				byte_was_read;
	char			*point;
	char			*tmp;

	if (line == NULL || fd < 0 || fd > 19 || BUFFER_SIZE <= 0 || BUFFER_SIZE
	> 2000)
		return (-1);
	point = check_ost(ost, line);
	if (point != NULL)
		return (1);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_was_read = read(fd, buf, BUFFER_SIZE);
	while (!point && (byte_was_read != 0))
	{
		buf[byte_was_read] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
		{
			*point = '\0';
			point++;
			ost = ft_strdup(point);
			tmp = *line;
			*line = ft_strjoin(tmp, buf);
			free(tmp);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		byte_was_read = read(fd, buf, BUFFER_SIZE);
	}
//	if (byte_was_read == 0 && ost == NULL)
//		return (0);
//	if (byte_was_read == 0 && ft_strlen(ost) == 0)
//		return (0);
	return (0);
}