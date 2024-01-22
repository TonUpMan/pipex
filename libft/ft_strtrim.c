/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:56:15 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/22 12:53:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	if (!s1)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i] != '\0')
		i++;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j - 1]) != 0 && j > 0)
		j--;
	if (i == ft_strlen(s1))
		i = 0;
	trim = ft_substr(s1, i, j - i);
	return (trim);
}
