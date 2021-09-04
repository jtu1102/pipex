/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:48:44 by soahn             #+#    #+#             */
/*   Updated: 2021/09/01 10:20:04 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_stdin(t_exe *x, int fd)
{
	char	*line;
	int		ret;

	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret < 0)
			error_exit(x);
		else
		{
			if (!ft_strncmp(line, x->limiter, ft_strlen(x->limiter)))
				break ;
			ft_putendl_fd(line, fd);
			s_free((void **)&line);
		}
	}
	close(fd);
}

void	heredoc_init(t_exe *x, int *argc, char *argv[])
{
	int	i;

	x->heredoc = true;
	x->tmp = "/tmp/.heredoc";
	x->limiter = argv[2];
	i = 1;
	while (++i < *argc)
		argv[i - 1] = argv[i];
	--(*argc);
}
