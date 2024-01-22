/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:36:17 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/17 11:24:34 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;

	if (!dst && size == 0)
		return (0);
	lendst = ft_strlen(dst);
	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size >= lendst)
		dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		return (lendst + ft_strlen(src));
}
