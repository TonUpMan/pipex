/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:05:19 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/11 12:38:28 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*schr;

	i = 0;
	schr = (char *)s;
	if (c == 0)
	{
		i = ft_strlen(s);
		return (&schr[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&schr[i]);
		i++;
	}
	return (NULL);
}
