/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:33:45 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/11 18:03:09 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*schr;
	unsigned int	i;

	i = 0;
	schr = (unsigned char *)s;
	while (i < n)
	{
		if (schr[i] == (unsigned char)c)
			return (&schr[i]);
		i++;
	}
	return (NULL);
}
