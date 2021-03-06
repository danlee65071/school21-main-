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
# include <errno.h>

# define RIGHTS S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | \
	S_IROTH | S_IWOTH | S_IXOTH

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
	int		path_ind;
}	t_pipex;

#endif
