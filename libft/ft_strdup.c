/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:41:33 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/08 14:46:12 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pdst;
	int		s1len;

	i = 0;
	s1len = ft_strlen1(s1);
	pdst = malloc(sizeof(char) * (s1len + 1));
	if (pdst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		pdst[i] = s1[i];
		i++;
	}
	pdst[i] = '\0';
	return (pdst);
}
