/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:07:38 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/12 15:10:54 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	size_t	sublen;
	char	*subs;

	if (!s)
		return (NULL);
	i = 0;
	sublen = 0;
	slen = (size_t)ft_strlen((char *)s);
	while (slen > start && i < len && i < slen)
	{
		i++;
		sublen++;
	}
	subs = (char *)malloc(sizeof(char) * (sublen + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len && slen > start)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}
