#include "../include/pipex.h"

char	*strappend(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s_calloc((void **)&res, s1_len + s2_len + 1, sizeof(char)))
		return (NULL);
	ft_strlcpy(res, s1, s1_len + 1);
	free(s1);
	ft_strlcpy(res + s1_len, s2, s2_len + 1);
	return (res);
}
