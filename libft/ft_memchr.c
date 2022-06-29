/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:43:40 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/07 08:14:34 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	uc;

	i = 0;
	ps = (unsigned char *) s;
	uc = (unsigned char) c;
	while (i < n)
	{
		if (ps[i] == uc)
			return (&ps[i]);
		i++;
	}
	return (0);
}
