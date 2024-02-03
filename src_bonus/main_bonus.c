/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/03 00:07:49 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_child(int argc, char **argv, char **envp, int *pipefd)
{
	int		i;
	int		pid;

	i = 2;
	while (i < (argc - 2))
	{
		pid = fork();
		if (pid == -1)
			mes_error("pipe", errno);
		if (pid == 0 && i < 3)
			childin(argv, envp, pipefd);
		else
			child_between(argv[i], envp, pipefd);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			pipefd[2];

	check_arg(argc, argv);
	if (pipe(pipefd) == -1)
		mes_error("pipe", errno);
	make_child(argc, argv, envp, pipefd);
	pid = fork();
	if (pid == -1)
		mes_error("fork", errno);
	if (pid == 0)
		childout(argv, argc, envp, pipefd);
	if (pid != 0)
		pipe_use(pipefd, 2);
	waitpid(-1, NULL, 0);
	return (0);
}
