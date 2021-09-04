/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:07:11 by soahn             #+#    #+#             */
/*   Updated: 2021/09/01 10:11:36 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	init_path(t_exe *x, char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	if (!(*envp))
		return (false);
	x->path = ft_split((*envp) + 5, ':');
	if (!(x->path))
		return (false);
	return (true);
}

static bool	init_cmd(t_exe *x)
{
	if (!s_calloc((void **)(&(x->cmd)), x->pipe + 1, sizeof(char **)))
		return (false);
	return (true);
}

static bool	parse_cmd(t_exe *x, char *cmd, int idx)
{
	char	*p;
	char	*tmp;
	int		i;

	x->cmd[idx] = ft_split(cmd, ' ');
	i = -1;
	while (x->path[++i])
	{
		p = ft_strjoin(x->path[i], "/");
		tmp = ft_strjoin(p, x->cmd[idx][0]);
		free(p);
		if (!access(tmp, F_OK))
		{
			free(x->cmd[idx][0]);
			x->cmd[idx][0] = tmp;
			return (true);
		}
		free(tmp);
	}
	return (false);
}

void	init(t_exe *x, int argc, char *argv[], char *envp[])
{
	int	i;
	int	cmd_num;

	cmd_num = argc - 3;
	x->in = argv[1];
	x->out = argv[argc - 1];
	if (!init_path(x, envp))
		error_exit(x);
	x->pipe = argc - 4;
	if (!init_cmd(x))
		error_exit(x);
	if (!s_calloc((void **)&(x->valid_cmd), cmd_num, sizeof(bool)))
		error_exit(x);
	i = -1;
	while (++i < cmd_num)
		x->valid_cmd[i] = true;
	i = -1;
	while (++i < cmd_num)
		if (!parse_cmd(x, argv[i + 2], i))
			cmd_not_fnd(x, i);
}

void	x_init(t_exe *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	i = 0;
	while (i < len)
		tmp[i++] = c;
}
