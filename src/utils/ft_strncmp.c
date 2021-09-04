/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:54:24 by soahn             #+#    #+#             */
/*   Updated: 2021/08/25 21:17:52 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (ptr_s1[i] && ptr_s2[i] && i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			break ;
		i++;
	}
	if (i == n)
		--i;
	return (ptr_s1[i] - ptr_s2[i]);
}
