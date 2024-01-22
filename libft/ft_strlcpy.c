/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:16:21 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/05 13:53:28 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"      

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	lsrc;
	unsigned int	i;

	lsrc = 0;
	i = 0;
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	while (i < size - 1 && i < lsrc)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lsrc);
}
