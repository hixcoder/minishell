/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:32:50 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/13 13:31:56 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	if (pdst > psrc)
	{
		i = len - 1;
		while (len-- > 0)
		{
			pdst[i] = psrc[i];
			i--;
		}
	}
	else
	{
		while (++i < len)
			pdst[i] = psrc[i];
	}
	return (dst);
}
