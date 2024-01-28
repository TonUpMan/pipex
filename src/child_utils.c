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
		free_all(path, cmd);
		mes_error("execve error", errno);
	}
}

void	pipe_in(int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
}

void	pipe_out(int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}

void	childin(char **argv, char **envp, int *pipefd)
{
	char	**cmd;
	char	*path;
	int		fdin;

	cmd = ft_split(argv[2], ' ');
	path = find_path(cmd, envp);
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
	{
		free_all(path, cmd);
		mes_error("fdin error", errno);
	}
	dup2(fdin, 0);
	close(fdin);
	pipe_in(pipefd);
	exec_cmd(path, cmd, envp);
	free_all(path, cmd);
}

void	childout(char **argv, char **envp, int *pipefd)
{
	char	**cmd;
	char	*path;
	int		fdout;

	cmd = ft_split(argv[3], ' ');
	path = find_path(cmd, envp);
	pipe_out(pipefd);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdout == -1)
	{
		free_all(path, cmd);
		mes_error("fdout error", errno);
	}
	dup2(fdout, 1);
	close(fdout);
	exec_cmd(path, cmd, envp);
	free_all(path, cmd);
}
