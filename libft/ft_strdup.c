/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:45:52 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/20 09:18:17 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		slen;
	void	*sdup;

	slen = ft_strlen(s);
	sdup = malloc(sizeof(char) * slen + 1);
	if (sdup == NULL)
		return (NULL);
	ft_strlcpy(sdup, s, slen + 1);
	return (sdup);
}
