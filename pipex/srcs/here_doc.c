/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:00:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/01 15:00:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	get_here_doc(char **argv, t_pipex bpipex)
{
	int	fd;

	fd = open("tmp_file", O_CREAT | O_WRONLY | O_TRUNC, B_RIGHTS);
	while (1)
	{
		if (get_next_line(0, &bpipex.buf) == -1)
			exit (1);
		if (ft_strncmp(argv[2], bpipex.buf, ft_strlen(argv[2]) + 1) == 0)
			break ;
		write(fd, bpipex.buf, ft_strlen(bpipex.buf));
		write(fd, "\n", 1);
		free(bpipex.buf);
	}
	close(fd);
}

void	here_doc(int argc, char **argv, char **envp, t_pipex bpipex)
{
	int	tmp_fd;

	bpipex.outfile = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY,
						  B_RIGHTS);
	bpipex.cmds_qnty = argc - 4;
	bpipex.pf_qnty = 2 * (bpipex.cmds_qnty - 1);
	bpipex.pf = malloc(sizeof(int) * bpipex.pf_qnty);
	bpipex.i = -1;
	get_here_doc(argv, bpipex);
	tmp_fd = open("tmp_file", O_RDONLY);
	while (++bpipex.i < bpipex.cmds_qnty - 1)
		pipe(bpipex.pf + 2 * bpipex.i);
	bpipex.i = -1;
	while (++bpipex.i < bpipex.cmds_qnty)
	{
		bpipex.pid = fork();
		if (bpipex.pid == 0)
		{
			if (bpipex.i == 0)
			{
				dup2(tmp_fd, 0);
				dup2(bpipex.pf[1], 1);
				close_pf(bpipex.pf, bpipex.pf_qnty);
			}
			else if (bpipex.i == bpipex.cmds_qnty - 1)
			{
				dup2(bpipex.pf[2 * bpipex.i - 2], 0);
				dup2(bpipex.outfile, 1);
				close_pf(bpipex.pf, bpipex.pf_qnty);
			}
			else
			{
				dup2(bpipex.pf[2 * bpipex.i - 2], 0);
				dup2(bpipex.pf[2 * bpipex.i + 1], 1);
				close_pf(bpipex.pf, bpipex.pf_qnty);
			}
			bpipex.cmd_args = ft_split(argv[3 + bpipex.i], ' ');
			bpipex.cmd_file = cmd_path_bonus(bpipex.cmds_dirs, bpipex.cmd_args[0]);
			execve(bpipex.cmd_file, bpipex.cmd_args, envp);
			free(bpipex.cmd_args);
			free(bpipex.cmd_file);
		}
	}
	close_pf(bpipex.pf, bpipex.pf_qnty);
	wait(0);
	close(tmp_fd);
}
