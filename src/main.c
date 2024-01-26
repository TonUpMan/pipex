/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/26 23:28:20 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid1;
	pid_t		pid2;
	int			pipefd[2];

	check_arg(argc, argv);
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(0);
	}
	pid1 = fork();
	if (pid1 == 0)
		childin(argv, envp, pipefd);
	if (pid1 != 0)
	{
		pid2 = fork();
		if (pid2 == 0)
			childout(argv, envp, pipefd);
		close(pipefd[0]);
		close(pipefd[1]);
	}
}
