/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:07:06 by soahn             #+#    #+#             */
/*   Updated: 2021/09/04 12:47:59 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	close_fd(t_exe *x, int i)
{
	if (i == 0)
		close(x->p1[WRITE]);
	else
	{
		if (!(i % 2))
		{
			close(x->p1[WRITE]);
			close(x->p2[READ]);
		}
		else
		{
			close(x->p1[READ]);
			close(x->p2[WRITE]);
		}
	}
}

static void	first_cmd(char **envp, t_exe *x)
{
	int	fd;

	if (x->heredoc)
	{
		fd = open_fd(x, x->tmp, O_CREAT | O_WRONLY | O_TRUNC);
		get_stdin(x, fd);
		close(fd);
		fd = open_fd(x, x->tmp, O_RDONLY);
	}
	else
		fd = open_fd(x, x->in, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(x->p1[WRITE], STDOUT_FILENO);
	if (x->valid_cmd[0])
		execve(x->cmd[0][0], x->cmd[0], envp);
	else
		exit(1);
}

static void	last_cmd(char **envp, t_exe *x, int i)
{
	int	fd;

	if (x->heredoc)
		fd = open_fd(x, x->out, O_WRONLY | O_CREAT | O_APPEND);
	else
		fd = open_fd(x, x->out, O_WRONLY | O_CREAT | O_TRUNC);
	if (!(i % 2))
	{
		dup2(x->p2[READ], STDIN_FILENO);
		close(x->p2[READ]);
	}
	else
	{
		dup2(x->p1[READ], STDIN_FILENO);
		close(x->p1[READ]);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (x->valid_cmd[x->pipe])
		execve(x->cmd[x->pipe][0], x->cmd[x->pipe], envp);
	else
		exit(1);
}

static void	child_process(char **envp, t_exe *x, int i)
{
	if (i == 0)
		first_cmd(envp, x);
	else if (i == x->pipe)
		last_cmd(envp, x, i);
	else
	{
		if (!(i % 2))
		{
			dup2(x->p2[READ], STDIN_FILENO);
			dup2(x->p1[WRITE], STDOUT_FILENO);
		}
		else
		{
			dup2(x->p1[READ], STDIN_FILENO);
			dup2(x->p2[WRITE], STDOUT_FILENO);
		}
		if (x->valid_cmd[i])
			execve(x->cmd[i][0], x->cmd[i], envp);
		else
			exit(1);
	}
}

void	my_execute(t_exe *x, char **envp)
{
	int		i;
	int		*pfd;
	pid_t	pid;
	int		status;

	i = -1;
	while (++i < x->pipe + 1)
	{
		if (!(i % 2))
			pfd = x->p1;
		else
			pfd = x->p2;
		if (pipe(pfd) < 0)
			error_exit(x);
		pid = fork();
		if (pid < 0)
			error_exit(x);
		else if (!pid)
			child_process(envp, x, i);
		else
		{
			close_fd(x, i);
			waitpid(pid, &status, 0);
		}
	}
}
