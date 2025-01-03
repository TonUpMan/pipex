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

void	exec_cmd(char *content, char **envp)
{
	char	**cmd;
	char	*path;

	if (ft_strchr(content, '/'))
	{
		cmd = find_cmd(content);
		if (cmd)
			path = content;
		else
		{
			ft_putendl_fd("no such file or directory", 2);
			exit(0);
		}
	}
	else
	{
		cmd = ft_split(content, ' ');
		path = find_path(cmd, envp);
	}
	check_cmd(path, cmd, content);
	execve(path, cmd, envp);
	free_all(path, cmd);
}

void	pipe_use(int *pipefd, int mode)
{
	if (mode == 2)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (mode == 1)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
	}
	if (mode == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}

void	childin(char **argv, char **envp, int *pipefd)
{
	int		fdin;

	fdin = open(argv[1], O_RDONLY, 0644);
	if (fdin == -1)
	{
		perror("open");
		pipe_use(pipefd, 2);
		exit(0);
	}
	dup2(fdin, 0);
	close(fdin);
	pipe_use(pipefd, 1);
	exec_cmd(argv[2], envp);
}

void	childout(char **argv, char **envp, int *pipefd)
{
	int		fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdout == -1)
		mes_error("open", errno);
	dup2(fdout, 1);
	close(fdout);
	pipe_use(pipefd, 0);
	exec_cmd(argv[3], envp);
}
