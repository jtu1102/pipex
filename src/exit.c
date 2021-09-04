/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:07:22 by soahn             #+#    #+#             */
/*   Updated: 2021/09/01 10:19:19 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(t_exe *x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < x->pipe + 1)
	{
		j = -1;
		while (x->cmd[i][++j])
			s_free((void **)&(x->cmd[i][j]));
		s_free((void **)(&(x->cmd[i])));
	}
	s_free((void **)&(x->cmd));
	s_free((void **)&(x->valid_cmd));
	i = -1;
	while (x->path[++i])
		s_free((void **)&(x->path[i]));
	s_free((void **)&(x->path));
	if (x->heredoc && !access(x->tmp, F_OK))
		unlink(x->tmp);
}

void	error_exit(t_exe *x)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	free_args(x);
	exit(1);
}

void	argc_error_exit(int bns)
{
	if (bns)
		ft_putendl_fd("usage: ./pipex [heredoc] infile \
cmd1 cmd2 cmd3 ... cmdn outfile", STDERR_FILENO);
	else
		ft_putendl_fd("usage: ./pipex infile cmd1 cmd2 outfile", STDERR_FILENO);
	exit(1);
}

void	cmd_not_fnd(t_exe *x, int i)
{
	ft_putstr_fd("zsh: command not found: ", STDOUT_FILENO);
	ft_putendl_fd(x->cmd[i][0], STDOUT_FILENO);
	x->valid_cmd[i] = false;
}
