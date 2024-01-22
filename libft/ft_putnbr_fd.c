/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:45 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/12 14:43:40 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative_int(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2", 2);
		nb = 147483648;
	}
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;
	int	tempmodulo;

	n = negative_int(n, fd);
	if (n >= 0)
	{
		if (n < 10)
		{
			temp = n + '0';
			write(fd, &temp, 1);
		}
		else
		{
			tempmodulo = n % 10 + '0';
			ft_putnbr_fd(n / 10, fd);
			write(fd, &tempmodulo, 1);
		}
	}
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
}
