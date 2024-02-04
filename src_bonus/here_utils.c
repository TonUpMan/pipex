/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:40:47 by qdeviann          #+#    #+#             */
/*   Updated: 2024/02/04 00:40:49 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (ft_strlen(s1) != ft_strlen(s2))
		return (2);
	return (0);
}
