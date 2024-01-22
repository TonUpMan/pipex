/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:43:24 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 14:56:18 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c) && (s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static char	**filling_tab(char const *s, char **tab, char c)
{
	int	i;
	int	y;

	y = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[y] = ft_substr(s, 0, i);
			if (!tab[y])
			{
				free_split(tab);
				break ;
			}
			s = (s + i);
			y++;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = ft_calloc(((count_word(s, c)) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	filling_tab(s, tab, c);
	return (tab);
}
