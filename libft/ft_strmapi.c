/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:24 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/17 11:00:35 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!s || !f)
		return (0);
	i = 0;
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
