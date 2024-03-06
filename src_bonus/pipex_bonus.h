/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:32 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/22 10:50:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

void	check_arg(int argc, char **argv);
void	check_here_arg(int argc, char **argv);
char	**find_cmd(char *argv);
char	*find_path(char **cmd, char **envp);
int		ft_strcmp(char *s1, char *s2);
int		ft_open(int argc, char **argv, int mode);
void	check_cmd(char *path, char **cmd, char *argv);
void	exec_cmd(char *argv, char **envp);
void	make_here(char **argv);
void	here_in(char **argv, int *pipefd);
void	childin(char **argv, char **envp, int *pipefd, int i);
void	child(char **argv, char **envp, int i);
void	childout(int argc, char **argv, char **envp, int mode);
void	pipe_use(int *pipefd, int mode);
void	free_all(char *str, char **tab);
void	mes_error(char *str, int code);
void	free_tabs(char **str);

#endif
