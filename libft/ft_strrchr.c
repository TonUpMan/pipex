/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:24:16 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/20 09:25:39 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = (char *)s;
	if (c == 0)
		return (&str[size]);
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return (&str[size]);
		size--;
	}
	return (NULL);
}
