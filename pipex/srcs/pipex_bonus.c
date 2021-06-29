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

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	bpipex;

	if (argc < 5)
		return (1);
	envp[BONUS_PATH_INDEX] += 5;
	bpipex.mode_outfile = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP
		| S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH;
	bpipex.cmds_dirs = ft_split(envp[BONUS_PATH_INDEX], ':');
	bpipex.infile = open(argv[1], O_RDONLY);
	bpipex.outfile = open(argv[argc - 1], O_RDWR | O_CREAT
			| O_TRUNC, bpipex.mode_outfile);

	bpipex.cmds_qnty = argc - 3;
	bpipex.pf = malloc(sizeof(int *) * (bpipex.cmds_qnty - 1));
	bpipex.i = -1;
	while (++i < bpipex.cmds_qnty - 1)
		bpipex.pf[i] = malloc(sizeof(int) * 2);
	bpipex.i = -1;
	while (++bpipex.i < bpipex.cmds_qnty)
	{
		if (pipe(bpipex.pf[i]) == -1)
			return (1);
		if (bpipex.i == 0)
			dup2(bpipex.infile, 0);
		else if (bpipex.i == bpipex.cmds_qnty - 1)
			dup2(bpipex.outfile, 1);
		
	}
	wait(0);

	close(bpipex.infile);
	close(bpipex.outfile);
	return (0);
}
