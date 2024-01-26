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

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	check_arg(int argc, char **argv);
char	*find_path(char **cmd, char **envp);
void	exec_cmd(char *path, char **cmd, char **envp);
void	childin(char **argv, char **envp, int *pipefd);
void	childout(char **argv, char **envp, int *pipefd);
void	free_tabs(char **str);
int		size_tab(char **str);

#endif
