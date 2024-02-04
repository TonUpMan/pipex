/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:40:47 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/04 00:40:49 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_arg(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc < 6)
	{
		ft_putendl_fd("expected: here_doc limiter cmd cmd1 outfile", 2);
		exit(EXIT_FAILURE);
	}
	check_empty(argc, argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (ft_strlen(s1) != ft_strlen(s2))
		return (2);
	return (0);
}

void	make_here(int argc, char **argv, char **envp)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 3;
	while(i != argc - 2)
	{
		if(pipe(pipefd) == -1)
			mes_error("pipe", errno);
		pid = fork();
		if(pid == 0 && i == 3)
		{
			pipe_use(pipefd, 1);
			get_next_limiter(0, argv[2]);
			exec_cmd(argv[3], envp);
		}
		else if (pid == 0 && i > 3 && i < argc - 2)
			child_btw(pipefd, argv[i], envp);
		else if (pid != 0)
			pipe_use(pipefd, 0);
		i++;
	}
	childout(argv, argc, envp);
	pipe_use(pipefd, 2);
}
