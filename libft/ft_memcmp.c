/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:10:57 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/29 11:17:43 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (i < n)
	{
		str1 = ps1[i];
		str2 = ps2[i];
		if (str1 != str2)
			return (str1 - str2);
		i++;
	}
	return (0);
}
