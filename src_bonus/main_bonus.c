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

void	make_child(int argc, char **argv, char **envp, int i)
{
	int			pipefd[2];
	pid_t		pid1;

	while (i != (argc - 2))
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
}

int	main(int argc, char **argv, char **envp)
{
	int		i;

	if(!ft_strcmp(argv[1], "here_doc"))
	{
		i = 4;
		get_next_limiter(0, argv[2]);
		make_child(argc, argv, envp, i);
	}
	else
	{
		i = 2;
		check_arg(argc, argv);
		make_child(argc, argv, envp, i);
	}
	return (0);
}
















