/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:13:22 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/03 19:09:08 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *save, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(save, buffer);
	free(save);
	return (tmp);
}

static char	*ft_read(int fd, char *save)
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
			free(save);
			return (NULL);
		}
		buffer[n_read] = 0;
		save = ft_join(save, buffer);
		if (!save || ft_strchr(save, '\n') || n_read < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (save);
}

static char	*ft_line(char *save)
{
	int		i;
	char	*new_line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	new_line = ft_substr(save, 0, i + 1);
	return (new_line);
}

static char	*ft_next_line(char *save)
{
	char	*next;
	int		j;
	int		k;

	j = 0;
	k = ft_strlen(save);
	while (save[j] && save[j] != '\n')
		j++;
	next = ft_substr(save, j + 1, k - j);
	if (!next[0])
	{
		free(next);
		free(save);
		save = NULL;
		return (NULL);
	}
	else
		free(save);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_calloc(1, sizeof(char));
	if (!save[fd])
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = ft_line(save[fd]);
	if (!line[0])
	{
		free(line);
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = ft_next_line(save[fd]);
	return (line);
}
