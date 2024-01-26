/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/22 10:50:26 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char		**path;
	char 		**option1;
	char 		**option2;
	pid_t		pid1;
	pid_t		pid2;
	int			fd1;
	int			fd2;
	int			pipefd[2];

	check_arg(argc, argv, envp);
	option1 = ft_split(argv[2], ' ');
	option2 = ft_split(argv[3], ' ');
	path = find_paths(argc, argv, envp);
	if(pipe(pipefd) == -1)
		ft_printf("erreur pipe!");
	pid1 = fork();
	if (pid1 == 0)
	{
		fd1 = open(argv[1], O_RDONLY);
		dup2(fd1, 0);
		close(fd1);
		close(pipefd[0]);				
		dup2(pipefd[1], 1);
		execve(path[0], option1, envp);
		exit(0);
	}
	if (pid1 != 0)	
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			fd2 = open(argv[4], O_WRONLY);
			dup2(fd2, 1);
			close(fd2);
			execve(path[1], option2, envp);
			exit(0);
		}
		close(pipefd[0]);
		close(pipefd[1]);
	}
}
