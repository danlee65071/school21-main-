/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:34:00 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/12 01:31:34 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_command(t_ps *all, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(all);
	else if (ft_strcmp(line, "sb") == 0)
		sb(all);
	else if (ft_strcmp(line, "ra") == 0)
		ra(all);
	else if (ft_strcmp(line, "rb") == 0)
		rb(all);
	else if (ft_strcmp(line, "pa") == 0)
		pa(all);
	else if (ft_strcmp(line, "pb") == 0)
		pb(all);
	else if (ft_strcmp(line, "rra") == 0)
		rra(all);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(all);
	else if (ft_strcmp(line, "ss") == 0)
		ss(all);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(all);
	else if (ft_strcmp(line, "rr") == 0)
		rr(all);
	else
		return (0);
	return (1);
}

void	reader(t_ps *all)
{
	size_t	fd;
	char	*line;

	fd = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!check_command(all, line))
		{
			ft_printf("ERROR");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	close(fd);
	if (check_if_sorted(all->head_a) && all->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
