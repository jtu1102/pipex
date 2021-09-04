/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:43:22 by soahn             #+#    #+#             */
/*   Updated: 2021/09/01 10:19:15 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef enum e_file
{
	READ,
	WRITE,
}	t_file;

typedef enum e_bonus
{
	MAND,
	BONUS,
}	t_bonus;

typedef struct s_exe
{
	char	*in;
	char	*out;
	char	**path;
	int		pipe;
	bool	*valid_cmd;
	char	***cmd;
	int		p1[2];
	int		p2[2];
	bool	heredoc;
	char	*limiter;
	char	*tmp;
}	t_exe;

/* execute.c */
void	my_execute(t_exe *x, char **envp);

/* exit.c */
void	free_args(t_exe *x);
void	error_exit(t_exe *x);
void	argc_error_exit(int bns);
void	cmd_not_fnd(t_exe *x, int i);

/* initial.c */
void	init(t_exe *x, int argc, char *argv[], char *envp[]);
void	x_init(t_exe *x, int c, size_t len);

/* utils */
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	s_calloc(void **ptr, size_t cnt, size_t n);
void	s_free(void **ptr);
void	*ft_memset(void *b, int c, size_t len);

/* gnl */
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);

/* heredoc.c (bonus) */
void	get_stdin(t_exe *x, int fd);
void	heredoc_init(t_exe *x, int *argc, char *argv[]);

/* open_fd */
int		open_fd(t_exe *x, char *file, int flag);

/* strappend */
char	*strappend(char *s1, char *s2);

#endif
