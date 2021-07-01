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

static void	close_pf(int *pf, int pf_qnty)
{
	int	i;

	i = -1;
	while (++i < pf_qnty)
		close(pf[i]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	bpipex;

	if (argc < 5)
		return (1);
	envp[BONUS_PATH_INDEX] += 5;
	bpipex.mode_outfile = B_RIGHTS;
	bpipex.cmds_dirs = ft_split(envp[BONUS_PATH_INDEX], ':');
	bpipex.infile = open(argv[1], O_RDONLY);
	bpipex.outfile = open(argv[argc - 1], O_RDWR | O_CREAT
			| O_TRUNC, bpipex.mode_outfile);

	bpipex.cmds_qnty = argc - 3;
	bpipex.pf_qnty = 2 * (bpipex.cmds_qnty - 1);
	bpipex.pf = malloc(sizeof(int) * bpipex.pf_qnty);
	bpipex.i = -1;
	while (++bpipex.i < bpipex.cmds_qnty - 1)
		pipe(bpipex.pf + 2 * bpipex.i);
	bpipex.i = -1;
	while (++bpipex.i < bpipex.cmds_qnty)
	{
		if (fork() == 0)
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
				dup2(2 * bpipex.i + 1, 1);
				close_pf(bpipex.pf, bpipex.pf_qnty);
			}
			bpipex.cmd_args = ft_split(argv[2 + bpipex.i], ' ');
			bpipex.cmd_file = cmd_path_bonus(bpipex.cmds_dirs, bpipex.cmd_args[0]);
			execve(bpipex.cmd_file, bpipex.cmd_args, envp);
			free(bpipex.cmd_args);
			free(bpipex.cmd_file);
		}
	}
	close_pf(bpipex.pf, bpipex.pf_qnty);
	bpipex.i = -1;
	while (++bpipex.i < bpipex.cmds_qnty)
		wait(0);
	close(bpipex.infile);
	close(bpipex.outfile);
	return (0);
}
