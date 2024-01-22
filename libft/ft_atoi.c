/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:25:30 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/20 09:12:08 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	tmp;
	int	n;

	i = 0;
	tmp = 0;
	n = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	while (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i + 1] == 43 || nptr[i + 1] == 45)
			return (0);
		if (nptr[i] == 45)
			n = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		tmp = tmp * 10 + (nptr[i] - '0');
		i++;
	}
	if (n == -1)
		tmp *= n;
	return (tmp);
}
