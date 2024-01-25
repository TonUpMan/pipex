#include "pipex.h"

char	**find_flags(char *argv)
{
	int		i;
	int		j;
	char	**tmp;
	char	**result;

	i = 0;
	j = 0;
	tmp = ft_split(argv, ' ');
	result = ft_calloc(size_tab(tmp), sizeof(char *));
	if (tmp[i])
	{
		while(tmp[i])
		{
			result[j] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]));
			i++;
			j++;
		}
		free_tabs(tmp);
		return (result);
	}
	return (NULL);
}
