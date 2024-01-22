/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:03 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/24 16:28:27 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexadd(unsigned long long int c, char *set, int len)
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
		len = ft_hexadd((c / base), set, len);
		len = ft_lputchar(set[tmpmod], len);
	}
	return (len);
}

int	ft_lprint_add(unsigned long long int c, char *set, int len)
{
	if (c == 0)
	{
		write(1, "(nil)", 5);
		return (len + 5);
	}
	if (c != 0)
	{
		len = ft_lputstr("0x", len);
		len = ft_hexadd(c, set, len);
	}
	return (len);
}
