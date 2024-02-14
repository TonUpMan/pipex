/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:04:24 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/06 02:05:02 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		return (-1);
	return (0);
}

void	here_in(char **argv, int *pipefd)
{
	char	*tmp;
	int		len;

	len = ft_strlen(argv[2]);
	pipe_use(pipefd, 1);
	while (1)
	{
		ft_putstr_fd("heredoc>", 0);
		tmp = get_next_line(0);
		if (tmp == NULL)
		{
			free(tmp);
			exit(0);
		}
		if (!ft_strncmp(tmp, argv[2], len) && ((int)ft_strlen(tmp) == len + 1))
		{
			free(tmp);
			exit(0);
		}
		ft_putstr_fd(tmp, 1);
		free(tmp);
	}
}

void	make_here(char **argv)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		mes_error("pipe", errno);
	pid = fork();
	if (pid == 0)
		here_in(argv, pipefd);
	else
	{
		pipe_use(pipefd, 0);
		waitpid(-1, NULL, 0);
	}
}
