/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/03 22:55:36 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid1;
	int			pipefd[2];
	int			i;

	i = 2;
	check_arg(argc, argv);
	while (i != argc -2)
	{
		if (pipe(pipefd) == -1)
			mes_error("pipe", errno);
		pid1 = fork();
		if (pid1 == 0 && i == 2)
			childin(argv, envp, pipefd);
		else if (pid1 == 0 && i > 2 && i < argc - 2)
			child_btw(pipefd, argv[i], envp);
		else if (pid1 != 0)
			pipe_use(pipefd, 0);
		i++;
	}
	childout(argv, argc, envp);
	pipe_use(pipefd, 2);
	return (0);
}
