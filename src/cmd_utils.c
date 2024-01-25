#include "pipex.h"

char	*find_flag(char *argv)
{
	int		i;
	char	**cmd;
	char	*tmp1;
	char	*tmp2;
	char	*result;

	i = 1;
	cmd = ft_split(argv, ' ');
	result = ft_substr(cmd[i], 0, ft_strlen(cmd[i]));
	if (size_tab(cmd) > 2)
	{
		while(cmd[i])
		{
			i++;
			tmp1 = ft_strjoin(" ", cmd[i]);
			tmp2 = ft_strjoin(result, tmp1);
			free(tmp1);
			free(result);
			result = ft_substr(tmp2, 0, ft_strlen(tmp2));
			free(tmp2);
		}
	}
	return (result);
}

char	**find_flags(int argc, char **argv)
{
	int		i;
	int		j;
	char	*flag;
	char	**result;

	i = 2;
	j = 0;
	result = ft_calloc((argc - 3), (sizeof(char *)));
	while(i < argc - 3)
	{
		flag = find_flag(argv[i]);
		if (flag == NULL)
			exit(0);
		result[j] = ft_substr(flag, 0, ft_strlen(flag));
		free(flag);
		i++;
		j++;
	}
	return (result);
}
