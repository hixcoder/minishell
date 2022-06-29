/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:01:56 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/10 16:54:42 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen3(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	size_t	j;

	j = 0;
	lendst = ft_strlen3((const char *)dst);
	lensrc = ft_strlen3(src);
	i = lendst;
	if (dstsize != 0 && lendst < dstsize)
	{
		while (i < (lensrc + lendst) && i < (dstsize - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (lendst + lensrc);
	}
	return (lensrc + dstsize);
}
