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
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

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
	int		i;
	int		cmds_qnty;
	int		pf_qnty;
	int		path_ind;
	char	*buf;
} t_pipex;

char	*cmd_path_bonus(char **cmds_dirs, char *cmd);
void	here_doc(int argc, char **argv, char **envp, t_pipex bpipex);
int		get_next_line(int fd, char **line);
int		find_path_ind(char **envp);
void	close_pf(int *pf, int pf_qnty);

#endif
