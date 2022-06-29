/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:27:09 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/08 10:27:01 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen6(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	while ((i < ft_strlen6(s1) || i < ft_strlen6(s2)) && i < n)
	{
		str1 = (unsigned char) s1[i];
		str2 = (unsigned char) s2[i];
		if (str1 != str2)
			return (str1 - str2);
		i++;
	}
	return (0);
}
