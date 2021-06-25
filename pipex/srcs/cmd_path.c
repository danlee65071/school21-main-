/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:56:18 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/25 21:56:19 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path(char **cmds_dirs, char *cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = -1;
	while (cmds_dirs[++i])
	{
		path = ft_strjoin(cmds_dirs[i], "/");
		tmp = path;
		path = ft_strjoin(path, cmd);
		free(tmp);
		if (access(path, 0) == 0)
			return (path);
	}
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" didn't find!\n", 2);
	exit (1);
}
