/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 07:52:09 by soahn             #+#    #+#             */
/*   Updated: 2021/08/31 13:00:02 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

size_t	check_word(char const *s, char c)
{
	size_t	chk;

	chk = 0;
	while (*s)
	{
		if (*s && *(char *)s == c)
			++s;
		else
		{
			while (*s && *(char *)s != c)
				s++;
			++chk;
		}
	}
	return (chk);
}

void	*malloc_error(char **s, size_t out_idx)
{
	size_t	i;

	i = 0;
	while (i < out_idx)
		free(s[i++]);
	free(s);
	return (NULL);
}

size_t	get_next_str(char **start, size_t next_str_len, char c)
{
	char	*to;

	*start += next_str_len;
	while (**start && **start == c)
		(*start)++;
	to = *start;
	while (*to && *to != c)
		to++;
	return (to - *start);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*from;
	size_t	cnt;
	size_t	i;
	size_t	next_str_len;

	cnt = check_word(s, c);
	out = malloc(sizeof(char *) * (cnt + 1));
	if (!out)
		return (NULL);
	i = 0;
	from = (char *)s;
	next_str_len = 0;
	while (i < cnt)
	{
		next_str_len = get_next_str(&from, next_str_len, c);
		if (!s_calloc((void **)&out[i], next_str_len + 1, sizeof(char)))
			return (malloc_error(out, i));
		ft_strlcpy(out[i++], from, (next_str_len + 1));
	}
	out[i] = NULL;
	return (out);
}
