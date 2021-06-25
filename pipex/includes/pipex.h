/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 00:23:38 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/22 00:23:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>

# define PATH_INDEX 1

typedef struct s_pipex
{
	int		pf[2];
	int		infile;
	int		outfile;
	int		is_pipe;
	int		pid1;
	int		pid2;
	char	*cmd_file;
	char	**cmds_dirs;
	char	**cmd_args;
	mode_t	mode_outfile;
}	t_pipex;

char	*cmd_path(char **cmds_dirs, char *cmd);

#endif
