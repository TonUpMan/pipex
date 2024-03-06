/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/06 02:07:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		mode;

	if (argc > 1 && !ft_strcmp(argv[1], "here_doc"))
	{
		i = 3;
		mode = 3;
		check_here_arg(argc, argv);
		make_here(argv);
	}
	else
	{
		i = 2;
		mode = 2;
		check_arg(argc, argv);
	}
	while (i < argc - 2)
	{
		child(argv, envp, i);
		i++;
	}
	childout(argc, argv, envp, mode);
	while (wait(NULL) > 0)
		;
	return (0);
}
