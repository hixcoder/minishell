/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:02:04 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/11 14:23:57 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen7(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_cheknd(const char *hay, const char *ndl, size_t hayi, size_t len)
{
	size_t	len_nedl;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	len_nedl = ft_strlen7(ndl) - 1;
	while (hay[i] == ndl[j] && (hayi + i) < len)
	{
		if (j == len_nedl)
			return (1);
		j++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (ft_cheknd(&haystack[i], needle, i, len) == 1)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
