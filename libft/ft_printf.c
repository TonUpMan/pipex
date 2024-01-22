/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:38:36 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 14:56:38 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format(va_list arg, char c, int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (c == 'c')
		len = ft_lputchar(va_arg(arg, int), len);
	if (c == 's')
		len = ft_lputstr(va_arg(arg, char *), len);
	if (c == 'p')
		len = ft_lprint_add(va_arg(arg, unsigned long long int), hexa, len);
	if (c == 'd' || c == 'i')
		len = ft_lputnbr(va_arg(arg, int), "0123456789", len);
	if (c == 'u')
		len = ft_lputnbr(va_arg(arg, unsigned int), "0123456789", len);
	if (c == 'x')
		len = ft_lput_hexa(va_arg(arg, unsigned int), hexa, len);
	if (c == 'X')
		len = ft_lput_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF", len);
	if (c == '%')
		len = ft_lputchar('%', len);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	if (!s)
		return (-1);
	va_start(arg, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", s[i + 1]))
			{
				len = format(arg, s[i + 1], len);
			}
			i++;
		}
		else
			len = ft_lputchar(s[i], len);
		i++;
	}
	va_end(arg);
	return (len);
}
