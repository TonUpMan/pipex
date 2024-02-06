/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:30:24 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/26 23:32:06 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char *str, char **tab)
{
	free(str);
	free_tabs(tab);
}

void	mes_error(char *str, int code)
{
	perror(str);
	exit(code);
}

void	free_tabs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_open(int argc, char **argv, int mode)
{
	int	fd;

	if (mode == 2)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 3)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}