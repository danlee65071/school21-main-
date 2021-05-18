/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:43:14 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 02:42:36 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output_commands(void)
{
	size_t	fd;
	char	*line;

	fd = 0;
	ft_printf("let commands = [");
	while (get_next_line(fd, &line) == 1)
	{
		write(1, "\"", 1);
		write(1, line, ft_strlen(line));
		write(1, "\", ", 3);
		free(line);
	}
	write(1, "];", 2);
}

void	output_args(char **av)
{
	int i;

	i = 2;
	ft_printf("let stack_a = [");
	while (av[i])
	{
		ft_printf("%d", ft_atoi(av[i]));
		if (av[i + 1])
			write(1, ", ", 2);
		else
			write(1, "];", 2);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ft_strcmp(av[1], "-a") == 0 && ac > 2)
		output_args(av);
	else if (ft_strcmp(av[1], "-c") == 0 && ac > 2)
		output_commands();
	else
		exit(EXIT_FAILURE);
	return (0);
}
