#include "pipex_bonus.h"

static char	*ft_join(char *save, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(save, buffer);
	free(save);
	return (tmp);
}

static char	*ft_read(int fd, char *line, char *limiter)
{
	char	*buffer;
	int		n_read;

	n_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (n_read != 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[n_read] = 0;
		line = ft_join(line, buffer);
		if (!line || ft_strnstr(line, limiter, ft_strlen(line)) || n_read < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (line);
}

void	get_next_limiter(int fd, char *limiter)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		ft_printf(NULL);
	line = ft_calloc(1, sizeof(char));
	if (!line)
		ft_printf(NULL);
	line = ft_read(fd, line, limiter);
	if (line == NULL)
		ft_printf(NULL);
	ft_printf("%s", line);
}