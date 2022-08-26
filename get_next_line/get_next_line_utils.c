/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:56:02 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/23 15:57:39 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*dst;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = (int)ft_strlen2(s1) + (int)ft_strlen2(s2) + 1;
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

char	*ft_strdup2(const char *s1)
{
	int		i;
	char	*pdst;
	int		s1len;

	i = 0;
	s1len = (int)ft_strlen2(s1);
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

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	size_t	sublen;
	char	*subs;

	if (!s)
		return (NULL);
	i = 0;
	sublen = 0;
	slen = (size_t)ft_strlen2((char *)s);
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
