/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:01:27 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/01 17:01:29 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	find_path_ind(char **envp)
{
	int	path_ind;

	path_ind = 0;
	while (ft_strncmp("PATH", envp[path_ind], 4))
		path_ind++;
	return (path_ind);
}

void	close_pf(int *pf, int pf_qnty)
{
	int	i;

	i = -1;
	while (++i < pf_qnty)
		close(pf[i]);
}