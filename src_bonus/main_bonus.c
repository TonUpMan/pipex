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

void	make_child(int argc, char **argv, char **envp)
{
	int			i;
	int			pipefd[2];
	pid_t		pid;

	i = 2;
	while (i != (argc - 2))
	{
		if (pipe(pipefd) == -1)
			mes_error("pipe", errno);
		pid = fork();
		if (pid == 0 && i == 2)
			childin(argv, envp, pipefd);
		else if (pid == 0 && i > 2 && i < argc - 2)
			child_btw(pipefd, argv[i], envp);
		else if (pid != 0)
			pipe_use(pipefd, 0);
		i++;
	}
	childout(argv, argc, envp);
	pipe_use(pipefd, 2);
}

int	main(int argc, char **argv, char **envp)
{
	if(!ft_strcmp(argv[1], "here_doc"))
	{
		check_here_arg(argc, argv);
		make_here(argc, argv, envp);
	}
	else
	{
		check_arg(argc, argv);
		make_child(argc, argv, envp);
	}
	return (0);
}
















