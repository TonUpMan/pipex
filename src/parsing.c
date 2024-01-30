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
			ft_putstr_fd("empty argument\n", 2);
			exit(2);
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
		ft_putstr_fd("not enough arguments\n", 2);
		exit(2);
	}
	check_empty(argc, argv);
	if (access(argv[1], F_OK | R_OK) == -1)
		mes_error("access", errno);
}
