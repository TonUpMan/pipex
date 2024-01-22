/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:24:04 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/11 10:55:01 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy(char *mdest, char *msrc, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		mdest[i] = msrc[i];
		i++;
	}
	return (mdest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*mdest;
	char	*msrc;

	mdest = (char *)dest;
	msrc = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			mdest[n - 1] = msrc[n - 1];
			n--;
		}
	}
	else
		copy(mdest, msrc, n);
	return (dest);
}
