/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:41:12 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/30 23:42:02 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_quote(char *argv)
{
	int		quote;
	int		i;

	quote = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == 39)
			quote++;
		i++;
	}
	if ((quote % 2) != 0)
	{
		ft_putendl_fd("not valid option", 2);
		exit(2);
	}
	return (quote);
}

static char	**filling_tab(char *argv, char **tab)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	y = 0;
	while (argv[i] != ' ')
		i++;
	tab[y] = ft_substr(argv, 0, i);
	y++;
	while (argv[i])
	{
		while (argv[i] != 39 && argv[i] != '\0')
			i++;
		j = i + 1;
		while (argv[j] != ' ' && argv[j] != '\0')
			j++;
		tab[y] = ft_substr(argv, i, ((j - i)));
		y++;
		i = j;
	}
	return (tab);
}

char	**split_quote(char *argv)
{
	char	**tab;

	tab = ft_calloc(((count_quote(argv) / 2) + 2), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	filling_tab(argv, tab);
	return (tab);
}
