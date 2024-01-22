/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:28:35 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/24 12:28:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lputnbr(long int c, char *set, int len)
{
	int	tmpmod;
	int	base;

	base = ft_strlen(set);
	if (c >= 0)
	{
		if (c < base)
		{
			len = ft_lputchar(set[c], len);
		}
		if (c >= base)
		{
			tmpmod = c % base + '0';
			len = ft_lputnbr((c / base), set, len);
			len = ft_lputchar(tmpmod, len);
		}
	}
	if (c < 0)
	{
		len = ft_lputchar('-', len);
		len = ft_lputnbr(-c, set, len);
	}
	return (len);
}
