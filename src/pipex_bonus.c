/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 00:07:14 by soahn             #+#    #+#             */
/*   Updated: 2021/09/04 21:31:14 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_exe	x;

	x_init(&x, 0, sizeof(t_exe));
	if (argc > 1 && !ft_strncmp(argv[1], "here_doc", 8))
		heredoc_init(&x, &argc, argv);
	if (argc < 5)
		argc_error_exit(BONUS);
	init(&x, argc, argv, envp);
	my_execute(&x, envp);
	free_args(&x);
}
