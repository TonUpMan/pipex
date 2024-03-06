/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:32:21 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/06 02:05:46 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	childin(char **argv, char **envp, int *pipefd, int i)
{
	int		fdin;

	fdin = open(argv[1], O_RDONLY, 0644);
	if (fdin == -1)
	{
		pipe_use(pipefd, 2);
		mes_error("open", errno);
	}
	dup2(fdin, 0);
	close(fdin);
	pipe_use(pipefd, 1);
	exec_cmd(argv[i], envp);
}

void	child(char **argv, char **envp, int i)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		mes_error("pipe", errno);
	pid = fork();
	if (pid == -1)
		mes_error("fork", errno);
	if (pid == 0 && i == 2)
		childin(argv, envp, pipefd, i);
	else if (pid == 0 && i > 2)
	{
		pipe_use(pipefd, 1);
		exec_cmd(argv[i], envp);
	}
	else
		pipe_use(pipefd, 0);
}

void	childout(int argc, char **argv, char **envp, int mode)
{
	int		fdout;

	fdout = ft_open(argc, argv, mode);
	if (fdout == -1)
		mes_error("open", errno);
	dup2(fdout, 1);
	close(fdout);
	exec_cmd(argv[argc - 2], envp);
}
