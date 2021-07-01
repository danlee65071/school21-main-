/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:37:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/06/26 19:37:58 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	child(t_pipex bpipex, char **argv, char **envp)
{
	bpipex.pid = fork();
	if (bpipex.pid == 0)
	{
		if (bpipex.i == 0)
		{
			dup2(bpipex.infile, 0);
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
		bpipex.cmd_args = ft_split(argv[2 + bpipex.i], ' ');
		bpipex.cmd_file = cmd_path_bonus(bpipex.cmds_dirs, bpipex.cmd_args[0]);
		execve(bpipex.cmd_file, bpipex.cmd_args, envp);
		free(bpipex.cmd_args);
		free(bpipex.cmd_file);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	bpipex;

	if (argc < 5)
		return (1);
	bpipex.path_ind = find_path_ind(envp);
	envp[bpipex.path_ind] += 5;
	bpipex.cmds_dirs = ft_split(envp[bpipex.path_ind], ':');
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc") + 1))
	{
		bpipex.cmds_qnty = argc - 3;
		bpipex.pf_qnty = 2 * (bpipex.cmds_qnty - 1);
		bpipex.pf = malloc(sizeof(int) * bpipex.pf_qnty);
		bpipex.infile = open(argv[1], O_RDONLY);
		if (bpipex.infile == -1)
		{
			perror("Error");
			return (1);
		}
		bpipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
							  B_RIGHTS);
		bpipex.i = -1;
		while (++bpipex.i < bpipex.cmds_qnty - 1)
			pipe(bpipex.pf + 2 * bpipex.i);
		bpipex.i = -1;
		while (++bpipex.i < bpipex.cmds_qnty)
			child(bpipex, argv, envp);
		close_pf(bpipex.pf, bpipex.pf_qnty);
		bpipex.i = -1;
		while (++bpipex.i < bpipex.cmds_qnty)
			wait(0);
	}
	else
	{
		here_doc(argc, argv, envp, bpipex);
		unlink("tmp_file");
	}
	free(bpipex.pf);
	close(bpipex.outfile);
	return (0);
}
