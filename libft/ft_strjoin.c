/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:58:13 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/12 13:53:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*news;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	news = ft_calloc((ls1 + ls2 + 1), sizeof(char));
	if (news == NULL)
		return (NULL);
	ft_memcpy(news, s1, ls1);
	ls2 = 0;
	while (s2[ls2] != '\0')
	{
		news[ls1] = s2[ls2];
		ls1++;
		ls2++;
	}
	return (news);
}
