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
	char 		**flags;
	int			i;
	int			fd1;
	//int			fd2;

	i = 0;
	check_arg(argc, argv, envp);
	flags = find_flags(argv[2]);
	path = find_paths(argc, argv, envp);
	fd1 = open(argv[1], O_RDONLY);
	dup2(fd1, 0);
	close(fd1);
	execve(path[0], flags, envp);


	return (0);
}
