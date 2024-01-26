/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:32:21 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/26 23:32:47 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *path, char **cmd, char **envp)
{
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve error");
		return ;
	}
}

void	childin(char **argv, char **envp, int *pipefd)
{
	char	**cmd;
	char	*path;
	int		fd1;

	cmd = ft_split(argv[2], ' ');
	path = find_path(cmd, envp);
	fd1 = open(argv[1], O_RDONLY);
	dup2(fd1, 0);
	close(fd1);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	exec_cmd(path, cmd, envp);
}

void	childout(char **argv, char **envp, int *pipefd)
{
	char	**cmd;
	char	*path;
	int		fd2;

	cmd = ft_split(argv[3], ' ');
	path = find_path(cmd, envp);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	fd2 = open(argv[4], O_WRONLY);
	dup2(fd2, 1);
	close(fd2);
	exec_cmd(path, cmd, envp);
}
