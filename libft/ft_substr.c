/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:32:35 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/16 14:58:02 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;
	size_t	len_m;

	if (!s)
		return (0);
	len_m = ft_strlen(s) - start;
	if (len_m >= len)
		len_m = len;
	if (start > ft_strlen(s))
		len_m = 0;
	news = malloc((len_m + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (i < len_m)
	{
		news[i] = s[start];
		i++;
		start++;
	}
	news[i] = '\0';
	return (news);
}
