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

void	check_cmd(char *path, char **cmd)
{
	if (path == NULL)
	{
		if (ft_strchr(cmd[0], '/'))
			ft_putendl_fd("no such file or directory", 2);
		if (!ft_strchr(cmd[0], '/'))
			ft_putendl_fd("command not found", 2);
		free_all(path, cmd);
		exit(2);
	}
}

char	**find_cmd(char *argv)
{
	char	**result;
	char	*tmp;

	result = ft_split(argv, ' ');
	tmp = ft_strrchr(result[0], '/');
	if (tmp == NULL)
		return (result);
	else
	{
		tmp = ft_strtrim(tmp, "/");
		free(result[0]);
		result[0] = ft_substr(tmp, 0, ft_strlen(tmp));
		free(tmp);
		return (result);
	}
	return (NULL);
}
