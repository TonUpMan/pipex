/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:15:29 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/11 11:41:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*smem1;
	unsigned char	*smem2;
	unsigned int	i;

	smem1 = (unsigned char *)s1;
	smem2 = (unsigned char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (smem1[i] != smem2[i])
			return (smem1[i] - smem2[i]);
		i++;
	}
	return (0);
}
