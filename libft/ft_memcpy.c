/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:44:15 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/20 12:12:40 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mdest;
	unsigned char	*msrc;
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	mdest = (unsigned char *) dest;
	msrc = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		mdest[i] = msrc[i];
		i++;
	}
	return (dest);
}
