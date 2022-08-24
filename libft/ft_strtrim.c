/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:17:31 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/24 12:54:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		inds;
	int		inde;
	int		j;
	char	*dst;
	int		len;

	inds = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	inde = (int)ft_strlen(s1);
	while (s1[inds] && ft_check(set, s1[inds]) == 1)
		inds++;
	while (inde > 0 && ft_check(set, s1[inde - 1]) == 1)
		inde--;
	if (inds >= inde)
		return (ft_strdup(""));
	len = inde - inds + 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	while (j < len && inds < inde)
		dst[j++] = s1[inds++];
	dst[j] = '\0';
	return (dst);
}
