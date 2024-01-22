/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:22 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/24 14:45:23 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lputstr(char *str, int len)
{
	size_t	i;
	size_t	size;

	if (!str)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		len = ft_lputchar(str[i], len);
		i++;
	}
	return (len);
}
