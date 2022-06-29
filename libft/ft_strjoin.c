/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:57:13 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/13 13:28:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
