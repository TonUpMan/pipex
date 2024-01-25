#include "pipex.h"

static char	**find_envpath(char **envp)
{
	int		i;
	char	*tmp;
	char	**result;

	i = 0;
	while (envp[i])
	{
		if(!ft_strncmp(envp[i], "PATH", 4))
		{
			tmp = ft_strtrim(envp[i], "PATH=");
			result = ft_split(tmp, ':');
			free(tmp);
			return (result);
		}
		i++;
	}
	if (i == size_tab(envp))
		ft_printf("Path non trouve!");
	return(NULL);
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

char	*find_path(char *argv, char **envp)
{
	int		i;
	char	*tmp;
	char	**paths;
	char	**cmds;
	char	*result;

	paths = find_envpath(envp);
	cmds = ft_split(argv, ' ');
	i = 0;
	while(paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if(ft_access(tmp, cmds[0]))
		{
			result = ft_strjoin(tmp, cmds[0]);
			free(tmp);
			free_tabs(paths);
			free_tabs(cmds);
			return (result);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	**find_paths(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	**result;

	i = 2;
	j = 0;
	result = ft_calloc((argc - 3), (sizeof(char *)));
	while(i < argc - 1)
	{
		path = find_path(argv[i], envp);
		if (path == NULL)
			exit(0);
		result[j] = ft_substr(path, 0, ft_strlen(path));
		free(path);
		i++;
		j++;
	}
	return (result);
}
