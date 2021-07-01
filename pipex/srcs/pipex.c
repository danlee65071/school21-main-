/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 00:10:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/22 00:10:43 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pf[1], 1);
	close(pipex.pf[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd_file = cmd_path(pipex.cmds_dirs, pipex.cmd_args[0]);
	execve(pipex.cmd_file, pipex.cmd_args, envp);
	free(pipex.cmd_args);
	free(pipex.cmd_file);
}

static void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pf[0], 0);
	close(pipex.pf[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd_file = cmd_path(pipex.cmds_dirs, pipex.cmd_args[0]);
	execve(pipex.cmd_file, pipex.cmd_args, envp);
	free(pipex.cmd_args);
	free(pipex.cmd_file);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	envp[PATH_INDEX] += 5;
	pipex.mode_outfile = RIGHTS;
	pipex.cmds_dirs = ft_split(envp[PATH_INDEX], ':');
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_RDWR | O_CREAT
			| O_TRUNC, pipex.mode_outfile);
	pipex.is_pipe = pipe(pipex.pf);
	if (pipex.is_pipe == -1)
		return (1);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex.pf[0]);
	waitpid(pipex.pid1, NULL, 0);
	close(pipex.pf[1]);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
