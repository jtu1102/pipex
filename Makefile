# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 19:18:55 by soahn             #+#    #+#              #
#    Updated: 2021/09/06 11:18:55 by soahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
NAME = pipex

HEADIR = ./include/
SRCDIR = ./src/
UTILDIR = ./src/utils/

SRCS = $(SRCDIR)execute.c \
$(SRCDIR)exit.c \
$(SRCDIR)initial.c \
$(SRCDIR)pipex.c \
$(SRCDIR)heredoc.c \
$(SRCDIR)fd.c \
$(UTILDIR)ft_calloc_free.c \
$(UTILDIR)ft_putendl_fd.c \
$(UTILDIR)ft_putstr_fd.c \
$(UTILDIR)ft_split.c \
$(UTILDIR)ft_strjoin.c \
$(UTILDIR)ft_strlcpy.c \
$(UTILDIR)ft_strncmp.c \
$(UTILDIR)ft_memset.c \
$(UTILDIR)get_next_line.c \
$(UTILDIR)get_next_line_utils.c \
$(UTILDIR)strappend.c

BNSRCS = $(SRCDIR)execute.c \
$(SRCDIR)exit.c \
$(SRCDIR)initial.c \
$(SRCDIR)pipex_bonus.c \
$(SRCDIR)heredoc.c \
$(SRCDIR)fd.c \
$(UTILDIR)ft_calloc_free.c \
$(UTILDIR)ft_putendl_fd.c \
$(UTILDIR)ft_putstr_fd.c \
$(UTILDIR)ft_split.c \
$(UTILDIR)ft_strjoin.c \
$(UTILDIR)ft_strlcpy.c \
$(UTILDIR)ft_strncmp.c \
$(UTILDIR)ft_memset.c \
$(UTILDIR)get_next_line.c \
$(UTILDIR)get_next_line_utils.c \
$(UTILDIR)strappend.c

OBJS = $(SRCS:.c=.o)
BNSOBJS = $(BNSRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(HEADIR) -o $@ -c $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADIR) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(BNSOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(BNSOBJS)
	$(CC) $(CFLAGS) -I $(HEADIR) -o $(NAME) $(BNSOBJS)

.PHONY : all clean fclean re bonus
