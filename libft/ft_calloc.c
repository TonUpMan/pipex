/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:01:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/17 10:56:48 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	unsigned long long	totall;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	totall = nmemb * size;
	if (totall / size != nmemb)
		return (NULL);
	ptr = malloc(totall);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, totall);
	return (ptr);
}
