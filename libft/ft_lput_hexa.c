/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lput_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:03 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/24 16:30:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lput_hexa(unsigned int c, char *set, int len)
{
	int		tmpmod;
	size_t	base;

	base = ft_strlen(set);
	if (c < base)
	{
		len = ft_lputchar(set[c], len);
	}
	if (c >= base)
	{
		tmpmod = c % base;
		len = ft_lput_hexa((c / base), set, len);
		len = ft_lputchar(set[tmpmod], len);
	}
	return (len);
}
