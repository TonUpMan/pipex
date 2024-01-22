/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:52:43 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/16 18:08:59 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*filling_tab(char *nbr, int n, int i)
{
	if (n < 0)
	{
		n = -n;
		nbr[0] = '-';
	}
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	while (n > 0)
	{
		nbr[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	if (n == -2147483648)
	{
		nbr = ft_strdup("-2147483648");
		return (nbr);
	}
	i = count(n);
	nbr = ft_calloc((i + 1), sizeof(char));
	if (nbr == NULL)
		return (NULL);
	filling_tab(nbr, n, i);
	return (nbr);
}
