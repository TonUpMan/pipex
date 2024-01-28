/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:26:46 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/26 23:27:30 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**find_envpath(char **envp, char **cmd)
{
	int		i;
	char	*tmp;
	char	**result;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			tmp = ft_strtrim(envp[i], "PATH=");
			result = ft_split(tmp, ':');
			free(tmp);
			return (result);
		}
		i++;
	}
	free_tabs(cmd);
	ft_putstr_fd("Unfound Path", 2);
	exit(2);
}

static int	ft_access(char *path, char *cmds)
{
	int		check;
	char	*cmd;

	cmd = ft_strjoin(path, cmds);
	check = access(cmd, F_OK);
	free(cmd);
	if (check == 0)
		return (1);
	else
		return (0);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**paths;
	char	*result;

	i = 0;
	paths = find_envpath(envp, cmd);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (ft_access(tmp, cmd[0]))
		{
			result = ft_strjoin(tmp, cmd[0]);
			free_all(tmp, paths);
			return (result);
		}
		free(tmp);
		i++;
	}
	free_tabs(cmd);
	free_tabs(paths);
	mes_error("command not found", 127);
	return (0);
}
