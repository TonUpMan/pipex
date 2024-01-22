/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:52 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/20 12:43:52 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*nbig;

	if (!big && len == 0)
		return (0);
	i = 0;
	j = 0;
	nbig = (char *)big;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if ((i + j) >= len)
				break ;
			if (little[j + 1] == '\0' && (i + j) < len)
				return (&nbig[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
