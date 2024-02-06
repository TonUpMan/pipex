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

void	exec_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	if (count_quote(argv))
		cmd = split_quote(argv);
	else
		cmd = find_cmd(argv);
	path = check_cmd(argv, cmd, envp);
	execve(path, cmd, envp);
	free_all(path, cmd);
	mes_error("execve", errno);
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
