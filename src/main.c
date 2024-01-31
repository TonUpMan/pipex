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
		mes_error("pipe", errno);
	pid1 = fork();
	if (pid1 == -1)
		mes_error("fork", errno);
	if (pid1 == 0)
	{
		//ft_printf("pid1 avant child=%d\n\n", pid1);
		childin(argv, envp, pipefd);
		//ft_printf("pid1 apres child=%d\n\n", pid1);
	}
	if (pid1 != 0)
	{
		//ft_printf("pid1 avant wait=%d\n\n", pid1);
		waitpid(pid1, 0, -1);
		//ft_printf("pid1 apres wait=%d\n\n", pid1);
		pid2 = fork();
		if (pid2 == -1)
			mes_error("fork", errno);
		if (pid2 == 0)
		{
			//ft_printf("pid2 avant child=%d\n\n", pid2);
			childout(argv, envp, pipefd);
			//ft_printf("pid2 apres child=%d\n\n", pid2);
		}
		//ft_printf("pid2(parent)=%d\n", pid1);
		pipe_use(pipefd, 2);
	}
	return (0);
}
