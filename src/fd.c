/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:55:16 by soahn             #+#    #+#             */
/*   Updated: 2021/09/01 10:20:44 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_fd(t_exe *x, char *file, int flag)
{
	int	fd;

	fd = open(file, flag, 0644);
	if (fd < 0)
		error_exit(x);
	return (fd);
}