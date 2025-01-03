/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:29:06 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/02 22:29:10 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmd(char *path, char **cmd, char *argv)
{
	if (path == NULL)
	{
		if (ft_strchr(argv, '/'))
			ft_putendl_fd("no such file or directory", 2);
		if (!ft_strchr(argv, '/'))
			ft_putendl_fd("command not found", 2);
		free_all(path, cmd);
		exit(2);
	}
}

char	**find_cmd(char *content)
{
	char	*tmp;
	char	**result;
	int		check;

	check = access(content, F_OK | X_OK);
	if (check == 0)
	{
		tmp = ft_strrchr(content, '/');
		result = ft_split(tmp, ' ');
		return (result);
	}
	return (NULL);
}
