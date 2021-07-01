/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:38:20 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/26 19:38:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>

# define BONUS_PATH_INDEX 0
# define B_RIGHTS S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | \
S_IROTH | S_IWOTH | S_IXOTH

typedef struct s_bpipex
{
	int		*pf;
	int		infile;
	int		outfile;
	int		pid;
	char	*cmd_file;
	char	**cmds_dirs;
	char	**cmd_args;
	mode_t	mode_outfile;
	int		i;
	int		cmds_qnty;
	int		pf_qnty;
} t_pipex;

char	*cmd_path_bonus(char **cmds_dirs, char *cmd);

#endif
