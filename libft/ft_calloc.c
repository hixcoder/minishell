/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:44:27 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/07 10:24:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			i;
	unsigned char	*t;

	p = malloc(count * size);
	if (p == NULL)
		return (p);
	i = -1;
	t = (unsigned char *)p;
	while (++i < (count * size))
		t[i] = 0;
	return (p);
}
