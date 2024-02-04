/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:28:41 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/26 23:29:57 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	full_space(char *argv)
{
	int	len;
	int	check;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	check = 0;
	while (argv[i])
	{
		if (argv[i] == 32)
			check++;
		i++;
	}
	if (len == check)
		return (0);
	return (1);
}

static void	check_empty(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i <= (argc - 1))
	{
		if (!full_space(argv[i]))
		{
			ft_putendl_fd("error: empty argument", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_arg(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc != 5)
	{
		ft_putendl_fd("expected: infile cmd1 cmd2 outfile", 2);
		exit(EXIT_FAILURE);
	}
	check_empty(argc, argv);
}
