/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:57:15 by soahn             #+#    #+#             */
/*   Updated: 2021/09/04 13:01:15 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_exe	x;

	x_init(&x, 0, sizeof(t_exe));
	if (argc != 5)
		argc_error_exit(MAND);
	init(&x, argc, argv, envp);
	my_execute(&x, envp);
	free_args(&x);
}
